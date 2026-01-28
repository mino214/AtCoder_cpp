#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n=0): n(n), bit(n+1, 0) {}

    void add(int i, long long v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }

    long long sum(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    long long rangeSum(int l, int r) const {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N + 1);
    BIT fw(N);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        fw.add(i, A[i]);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x; // swap A[x] and A[x+1]

            long long old1 = A[x], old2 = A[x + 1];
            swap(A[x], A[x + 1]);

            // reflect changes in BIT (delta updates)
            fw.add(x,     A[x]     - old1);
            fw.add(x + 1, A[x + 1] - old2);

        } else { // type == 2
            int l, r;
            cin >> l >> r;
            cout << fw.rangeSum(l, r) << '\n';
        }
    }

    return 0;
}
/*
【問題概要（整理）】

長さ N の数列 A = (A1, A2, ..., AN) が与えられる。
Q 個のクエリを順に処理する。

■ クエリの種類
(1) 1 x
    Ax と A(x+1) を入れ替える（swap）

(2) 2 l r
    l ≤ i ≤ r の範囲の総和 Σ Ai を求める

■ 制約
- 2 ≤ N ≤ 2×10^5
- 1 ≤ Q ≤ 5×10^5
- 1 ≤ Ai ≤ 10^4
- クエリ1: 1 ≤ x ≤ N-1
- クエリ2: 1 ≤ l ≤ r ≤ N
- 入力はすべて整数

■ 入力形式
N Q
A1 A2 ... AN
query1
query2
...
queryQ

query は以下のどちらか:
- 1 x
- 2 l r

■ 出力
タイプ2（2 l r）のクエリの回数を q として、
それぞれの答えを q 行に出力する（クエリ2が出てきた順）。

■ 例（動作イメージ）
- 1 x: 隣同士をswapして配列が更新される
- 2 l r: 現在の配列の区間和を答える
*/

// https://atcoder.jp/contests/abc442/tasks/abc442_d
