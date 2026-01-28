#include<iostream>
#include<numeric>
using namespace std;
int main() {
    int n,x,y;
    int count=0; // gcdは最大公約数
    cin>>n>>x>>y;
    count = ( n/x + n/y ) -  n / (x / gcd(x,y) * y);
    cout << count;
}
/* 問題文
N 以下の正の整数の中で、
X の倍数または
Y の倍数であるものの個数はいくつありますか？

制約
1≤N≤10^6
1≤X<Y≤10^6
入力はすべて整数 */

/* コード定番
*#include <iostream>
#include <numeric>
using namespace std;

int main() {
long long n, x, y;
cin >> n >> x >> y;

long long g = std::gcd(x, y);
long long l = x / g * y;

long long ans = n / x + n / y - n / l;
cout << ans << '\n';
return 0;
} */