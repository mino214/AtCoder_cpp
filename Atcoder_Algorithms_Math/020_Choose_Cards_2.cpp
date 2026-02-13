#include<iostream>
#include<vector>
using namespace std;
constexpr int S = 1000;
int main(){
    int N;

    cin >> N;
    vector<int> A(N);

    long long DP[6][S + 1]= {};
    DP[0][0] = 1;

    for(int i = 0; i < N; i++)  cin >> A[i];

    for (const int a : A) {
        for (int i = 4 ; i >= 0; i--) {
            for (int sum = S - a ; sum >= 0; --sum)
                DP[i + 1][sum + a] += DP[i][sum];
        }
    }

    cout<<DP[5][S];
}
/*
* 問題文
- N 枚のカードがあり、左から i番目のカードには整数Aiが書かれています。
- カードを5枚選ぶ方法のうち、選んだカードに書かれた整数の和がちょうど1000 となるものは何通りありますか。

* 制約
- 5≤N≤100
- 1≤Ai≤1000
- 入力はすべて整数
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_t