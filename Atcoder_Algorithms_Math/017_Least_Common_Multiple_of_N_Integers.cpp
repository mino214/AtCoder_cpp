#include<iostream>
#include <numeric>
using namespace std;

long long lcm(long long a, long long b) {
    long long t = gcd(a, b);
    return a / t * b;
}

int main() {
    int n;
    long long g = 1;

    cin>>n;
    for(int i = 0; i < n; i++) {
        long long a;
        cin>>a;

    }
}
/*
* 問題文
- N 個の正の整数A1, A2...., ANの最小公倍数を求めてください。

* 制約
- 2≤N≤10^5
- 2≤Ai≤10^18
- 入力はすべて整数
- 問題の答えは10^18以下である
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_q