# 素数を求める方法
:素数を求める方法としては三つがあります。

## 1.素数判定
- 基本：√n まで割り算
- ２から√nまで割り切れるかをチェックします
- 計算量　:　O(√n)
- ポイント : **偶数を最初に弾いて、後に奇数だけ試すと2倍速いです。**

### 例
```
n = 97 
√97 ≈ 9.8なので　2, 3, 5, 7 だけ調べればOK
```

## 2.整数列挙
- エラトステネスの篩(ふるい)
- 2から順番に倍数を消していく
- 計算量 : O(N log log N) -> 速い
- Nが10^7くらいまでなら現実的に強い

### 流れ
```
1. 2 ~ Nを「全部素数候補」とする
2. 2の倍数を消す
3. 次の残った３の倍数を消す
3. √Nまで繰り返す
```

## 3. Nがめちゃ大きい素数の判断(10^12 ~ 10^18)
- Miller-Rabin(確率的 / もしくは64bit決め打ちで実用的に決定的）
- 割り算で間に合わない領域に使います
- 64bitの整数なら、決め持ちのテスト基数で実質「決定的」にできる実装が有名です

### 例
```
1.	n-1 = d \times 2^s に分解（dは奇数）

2.	いくつかの 決め打ち base a で
	•	x = a^d mod n
	•	x=1 または x=n-1 ならOK
	•	それ以外は x <- x^2 mod n を最大 s-1 回。途中で n-1 になればOK
	•	ならなければ 合成数

```

### コード
```　c++
#include <bits/stdc++.h>
using namespace std;

using u64  = unsigned long long;
using u128 = __uint128_t;

// (a * b) % mod をオーバーフローせず計算
u64 modMultiply(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

// (base^exp) % mod を繰り返し二乗法で計算
u64 modPow(u64 base, u64 exp, u64 mod) {
    u64 result = 1;
    while (exp > 0) {
        if (exp & 1) result = modMultiply(result, base, mod);
        base = modMultiply(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// n-1 = d * 2^s に分解（dは奇数）
void factorNminus1(u64 n, u64 &d, u64 &s) {
    d = n - 1;
    s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
}

// base a が n の合成性を示す（witness）か？
bool isWitness(u64 a, u64 n, u64 d, u64 s) {
    if (a % n == 0) return false;          // a==n 等はwitnessにならない

    u64 x = modPow(a % n, d, n);
    if (x == 1 || x == n - 1) return false;

    for (u64 i = 1; i < s; ++i) {
        x = modMultiply(x, x, n);
        if (x == n - 1) return false;
    }
    return true; // witness発見 → 合成数
}

// Miller–Rabin（64bit向け実用決定版）
bool isPrime(u64 n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    u64 d, s;
    factorNminus1(n, d, s);

    // 64bitで定番の bases（これで実用上決定的）
    static const u64 bases[] = {
        2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL
    };

    for (u64 a : bases) {
        if (isWitness(a, n, d, s)) return false;
    }
    return true;
}

int main() {
    u64 n;
    cin >> n;
    cout << (isPrime(n) ? "Yes\n" : "No\n");
}
```

## どれを使うべき？
- 1個だけ判定（n ≤ 10^13 くらい） → √n判定（偶数カット＋奇数だけ）でも行けること多い
- 1〜N の素数を全部 → エラトステネスの篩
- n が 10^18 近い → Miller–Rabin
