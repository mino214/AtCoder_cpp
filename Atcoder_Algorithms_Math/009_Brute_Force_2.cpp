#include<iostream>
using namespace std;
int main() {
    int n,s;
    int a[60];
    bool used[60] ={false};
    bool flag =false;

    string ans="No";
    cin>>n>>s;

    for (int i = 0 ; i < n ; i++)
        cin >> a[i];

    for (int i = 0 ; i < n ; i++) {

    }
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
