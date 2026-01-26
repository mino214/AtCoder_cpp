#include<iostream>
#include<vector>
using namespace std;
int main() {
    return 0;
}

/*
【問題概要（整理）】

長さ N の数列 A = (A1, A2, ..., AN) が与えられる。
Q 個のクエリを順に処理する。

■ クエリの種類
(1) 1 x
    Ax と A(x+1) を入れ替える（swap）

(2) 2 l r
    l ≤ i ≤ r の範囲の総和 Σ Ai を求める

■ 制約
- 2 ≤ N ≤ 2×10^5
- 1 ≤ Q ≤ 5×10^5
- 1 ≤ Ai ≤ 10^4
- クエリ1: 1 ≤ x ≤ N-1
- クエリ2: 1 ≤ l ≤ r ≤ N
- 入力はすべて整数

■ 入力形式
N Q
A1 A2 ... AN
query1
query2
...
queryQ

query は以下のどちらか:
- 1 x
- 2 l r

■ 出力
タイプ2（2 l r）のクエリの回数を q として、
それぞれの答えを q 行に出力する（クエリ2が出てきた順）。

■ 例（動作イメージ）
- 1 x: 隣同士をswapして配列が更新される
- 2 l r: 現在の配列の区間和を答える
*/

// https://atcoder.jp/contests/abc442/tasks/abc442_d
