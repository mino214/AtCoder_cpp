#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<vector<char>> dp(n + 1, vector<char>(s + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (!dp[i][j]) continue;
            dp[i + 1][j] = 1;
            if (j + A[i] <= s) dp[i + 1][j + A[i]] = 1;
        }
    }

    cout << (dp[n][s] ? "Yes" : "No") << '\n';
    return 0;
}

/*
*問題文
N 枚のカードが横一列に並べられています。左から
i 番目
(1≤i≤N) のカードには整数
A(i)が書かれています。

カードの中からいくつかを選んで、合計がちょうど
S となるようにする方法はありますか。
*/
// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_i
