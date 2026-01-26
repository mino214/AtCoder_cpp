#include<iostream>
#include <vector>
using namespace std;

long long comb(long long k) {
  if (k < 3) return 0;
  return k*(k-1)*(k-2)/6;
}
int main() {
  int n,m;
  cin>>n>>m;
  vector<int> deg(n + 1, 0);
  for(int i = 1; i <= m; i++) {
    int a,b;
    cin>>a>>b;
    deg[a]++;
    deg[b]++;
  }
  for (int i = 1; i <= n; i++) {
    long long k = (long long)(n - 1)  - deg[i];
    cout << comb(k) <<' ';
  }
  return 0;
}
/*
【問題概要 / 要約】

■ 登場人物
- 研究者が N 人（番号 1..N）
- 利害関係（辺）が M 個ある
  i=1..M について、研究者 Ai と Bi は互いに利害関係にある（無向）

■ 査読者の条件（著者が i の論文）
- 査読者は「相異なる 3 人」の研究者
- 3 人全員が著者 i とは別人（= i を含まない）
- 3 人全員が著者 i と利害関係にない（= i と辺でつながっていない）

■ 問い
- 各 i=1..N について、
  「著者 i の論文の査読者として選べる 3 人組」は何通りあるか求めよ。

■ 言い換え
- i と利害関係がある研究者集合を N(i) とすると、
  i を除き、かつ N(i) を除いた集合から 3 人を選ぶ通り数。
  つまり、候補人数 K = (N-1) - deg(i) として、答えは C(K, 3)。

■ 制約
- 1 <= N <= 2 * 10^5
- 0 <= M <= 2 * 10^5
- 1 <= Ai, Bi <= N, Ai != Bi
- 同じ無向辺の重複なし
  (Ai,Bi) != (Aj,Bj) かつ (Ai,Bi) != (Bj,Aj)（i!=j）
- 入力はすべて整数
 *
 * https://atcoder.jp/contests/abc442/tasks/abc442_c
 */

// 僕の場合は最初はvisitでチェックしながら解くつもりでしたが、時間がO(n^2)なるので、
// 違う方法で考える必要がありました。

// このような問題では
// 次数(degree), 余事象(complement)、組み合わせ（nC3)が必要です


