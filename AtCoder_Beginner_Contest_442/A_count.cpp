
#include<iostream>
using namespace std;

int main() {
    string s;
    int sum = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'i' || s[i] =='j')
            sum++;
    }
    cout << sum << endl;
    return 0;
}
/*
*問題文
英小文字からなる文字列
S が与えられます。
ここで、英小文字に含まれるドットの個数を以下のようにして定めます。

英小文字が i または j であるとき : 1 個
英小文字が i, j のいずれでもないとき : 0 個
S のすべての文字に対するドットの個数の和を求めてください。

制約
S は長さ
1 以上
10 以下の英小文字からなる文字列

入力例　：　aiiaj
出力例　：　3

https://atcoder.jp/contests/abc442/tasks/abc442_a
*/
