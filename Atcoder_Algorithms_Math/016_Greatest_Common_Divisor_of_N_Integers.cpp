#include<iostream>
#include <numeric>
using namespace std;
int main() {
    int n;
    cin>>n;

    long long g;
    cin>>g;

    for (int i = 1; i < n; i++) {
        long long An;
        cin>>An;
        g = gcd(An,g);
    } cout<<g;
}

/*
* 問題文
- N個の正の整数 A1,A2...,ANの最大公約数を求めてください。
* 制約
- 2≤N≤10^5
- 2≤Ai≤10^18
- 入力はすべて整数
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_p