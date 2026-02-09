#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {

    long long n;
    cin >> n;

    vector<long long> primes;
    while (n % 2 == 0) {
        primes.push_back(2);
        n /= 2;
    }

    for (long long i = 3; i <=n / i; i+=2) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        primes.push_back(n);

    for (auto p : primes)
        cout << p << " ";
}

/*
* 問題文
- 自然数Nを素因数分解するプログラムを作成してください。
- なお、任意の自然数の素因数分解は一意となることが知られています。

* 制約
- 2≤N≤10^12
- N は整数
* 出力
- N の素因数を、小さい順に空白区切りで出力してください。
- ただし、同じ素因数でNを複数回割ることができる場合は、その素因数は回数分出力してください。
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_n