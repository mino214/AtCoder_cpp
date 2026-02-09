#include<iostream>
#include <numeric>
using namespace std;

int main() {
    long long  a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}

/* 最大公約数
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}　*/

/* 最小公約数
    long long g = gcd(a,b);
    long long l = a / g * b;
*/

/*
* 問題文
- A と B の最大公約数を求めてください。

* 制約
- 1≤A,B≤10^9
- A,B は整数
 */