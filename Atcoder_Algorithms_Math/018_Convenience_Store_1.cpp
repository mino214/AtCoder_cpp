#include<iostream>
using namespace std;
int main() {
    int n;
    long long A_Count[4] ={0};

    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;

        if (a == 100)
            A_Count[0]++;
        else if (a == 200)
            A_Count[1]++;
        else if (a == 300)
            A_Count[2]++;
        else
            A_Count[3]++;
    }
    cout << A_Count[0] * A_Count[3]  + A_Count[1] * A_Count[2];
}

/*
* 問題文
- コンビニには N 個の品物が売られており、i 番目（1≤i≤N）の商品の値段は Ai円です。
- 異なる 2つの品物を買う方法のうち、合計金額が500円となるものは何通りありますか。

* 制約
- 2≤N≤200000
- Aiは  100,200,300,400 のいずれか
- 入力はすべて整数
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_r