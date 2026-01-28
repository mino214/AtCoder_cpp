#include<iostream>
using namespace std;
int main() {
    int n,s;
    int count = 0;
    cin>>n>>s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j<=n ; j++ ) {
            if (i + j <= s)
                ++count;
            else
                break;
        }
    }
    cout<<count;
}
/*
*問題文
赤・青のカードが各
1 枚ずつあり、あなたはそれぞれのカードに 1 以上 N 以下の整数を 1 つ書き込みます。

カードに書かれた整数の合計が
S 以下となる書き方は、いくつありますか？

制約
1≤N≤1000
1≤S≤2000
入力はすべて整数 */

/* O(1)バージョン
* #include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, S;
    cin >> N >> S;

    // i, j は 1..N、合計は 2..2N
    // 求めたいのは i+j <= S を満たす組 (i, j) の個数

    // S が 2N を超えても意味がないので、上限を 2N に切る
    long long U = min(S, 2LL * N); // U = min(S, 2N)

    // そもそも最小の和は 2 (1+1) なので、U<2 なら 0 通り
    if (U < 2) {
        cout << 0 << '\n';
        return 0;
    }

    // U=2N なら制約 i+j<=U は常に真（全てOK）→ N^2 通り
    if (U == 2LL * N) {
        cout << N * N << '\n';
        return 0;
    }

    long long ans = 0;

    // 和 t=i+j を固定して数える
    // t が 2..U のときの組数を足し合わせる
    //
    // 組数 f(t) は以下：
    // - t <= N+1 のとき f(t) = t-1
    // - t >  N+1 のとき f(t) = 2N - t + 1

    if (U <= N + 1) {
        // t=2..U はすべて前半（増加部分）
        // sum_{t=2..U} (t-1) = 1 + 2 + ... + (U-1)
        ans = (U - 1) * U / 2;
    } else {
        // 前半 t=2..N+1 の合計：
        // 1 + 2 + ... + N = N(N+1)/2
        ans = N * (N + 1) / 2;

        // 後半 t=N+2..U の合計（減少部分）
        // f(t) = 2N - t + 1 は等差数列になる
        long long m = U - (N + 1);          // 項数（t=N+2 から U までの個数）
        long long first = N - 1;            // t=N+2 のとき f(t)=2N-(N+2)+1 = N-1
        long long last  = 2 * N - U + 1;    // t=U のとき f(t)=2N-U+1
        ans += m * (first + last) / 2;      // 等差数列の和
    }

    cout << ans << '\n';
    return 0;
}
 */

/* O(N)
long long ans=0;
for (int i=1;i<=N;i++){
    long long k = S - i;
    if (k >= 1) ans += min((long long)N, k);
}
 */


// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_h