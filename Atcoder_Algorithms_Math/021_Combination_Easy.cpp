#include<iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}
int main() {
    int n, r;
    long long nCk;
    cin>>n>>r;

    nCk = factorial(n) / (factorial(r) * factorial(n - r));
    cout<<nCk;
}
/*
 * 問題文
- 整数n,r が与えられます。
- nCrを出力するプログラムを作成してください。

* 制約
- 1≤r≤n≤20
- 入力はすべて整数

* 公式
-  nCk = n! / ( k! * (n-k)! )

*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_u