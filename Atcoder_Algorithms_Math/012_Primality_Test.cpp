#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long long n;
    bool prime = true;
    cin >> n;

    long long sqrt_num = sqrt(n);
    for (int i = 2; i <= sqrt_num; i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    cout << (prime ? "Yes" : "No");
}

/* 良いコード
* 問題文
- N が素数であるかどうかを判定してください。

* 制約
- 2≤N≤10^13
- N は整数

* 出力
- Nが素数である場合は Yes を、素数でない場合は No を出力してください
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_l

/*
* #include <iostream>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

long long n;
cin >> n;

if (n < 2) { cout << "No"; return 0; }
if (n == 2 || n == 3) { cout << "Yes"; return 0; }
if (n % 2 == 0 || n % 3 == 0) { cout << "No"; return 0; }

for (long long i = 5; i * i <= n; i += 6) {
if (n % i == 0 || n % (i + 2) == 0) {
cout << "No";
return 0;
}
}
cout << "Yes";
return 0;
}
*/
