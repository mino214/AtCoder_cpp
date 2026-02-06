#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

   vector<bool> prime_arr(n + 1, true);
   prime_arr[0] = false; prime_arr[1] = false;

    for(int i = 2 ; i<=n ; i++) {
        if(prime_arr[i]) {
            cout << i << " ";
            for (int j = i * 2 ; j<=n ; j +=i)
                prime_arr[j] = false;
        }
    }
}

/*
* 問題文
- N 以下の素数を、小さい順に出力してください。

* 制約
- 2≤N≤3000
- N は整数
*/

// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_k