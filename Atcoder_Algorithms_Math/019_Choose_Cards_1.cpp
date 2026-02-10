#include<iostream>
using namespace std;
int main() {
    int n;
    long long cnt = 0;
    int A_count[3]={0};
    cin >> n;

    for (int i=0 ; i<n ; ++i) {
        int a; cin >> a;

        if (a == 1)
            A_count[0]++;
        else if (a == 2)
            A_count[1]++;
        else
            A_count[2]++;
    }

    for (int i=0 ; i<3 ; ++i) {
        if (A_count[i] <=1 )
            continue;
        for (int j = A_count[i]-1 ; j >= 0 ; j--)
            cnt += j ;
    }
    cout << cnt << endl;
}
/*
* 問題文
- N枚のカードがあり、左からi番目(1≤i≤N）のカードの色はAiです。
- Ai=1 のとき赤色、Ai=2 のとき黄色、Ai=3 のとき青色です。同じ色のカードを2枚選ぶ方法は何通りありますか。

* 制約
- 2≤N≤500000
- 1≤Ai≤3
- 入力はすべて整数
*/

// もっといいコード
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long c[4] = {0};
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        c[a]++;
    }

    long long ans = 0;
    for (int v = 1; v <= 3; ++v) {
        ans += c[v] * (c[v] - 1) / 2;
    }
    cout << ans;
}
 */


// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s