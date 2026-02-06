#include<iostream>
using namespace std;
int main() {
    int N;
    cin >> N;

    long long sum = 1;
    for (int i=1 ; i<=N ; i++)
        sum *= i;
    cout<<sum;
}
/*
* 問題文
- N! の値を求めてください。

* 制約
- 1≤N≤20
- N は整数
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_j