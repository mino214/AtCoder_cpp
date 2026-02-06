#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {

    long long n;
    cin >> n;

    vector<long long> v;

    long long  num = sqrt(n);
    for (long long i = 1; i <= num ; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n/i)
                v.push_back(n/i);
        }
    }

    sort(v.begin(),v.end());

    for (auto i = v.begin(); i != v.end(); i++)
        cout<<*i<<" ";
}
/*
* 問題文
- 整数
- Nが与えられます。
- Nの約数を列挙してください。

* 制約
- 1≤N≤10^13
- N は整数

* 出力
- Nの約数を改行区切りで出力してください。 出力する順番は任意ですが、同じ数が 2 回以上出力されてはいけません。
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_m