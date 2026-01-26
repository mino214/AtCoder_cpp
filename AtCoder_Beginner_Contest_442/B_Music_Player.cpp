#include<iostream>
using namespace std;

int main() {
    int A;
    int Q, volume = 0;
    bool status = false;

    cin >> Q;
    for (int i= 0 ; i < Q ; i++) {
        cin >> A;
        switch (A) {
            case 1: //  音量を 1 上げる (volume++)
                ++volume;
                break;
            case 2:
                if (volume >= 1)
                    --volume;
                break;
            case 3:
                status = !status;
                break;
            default:
                break;
        }

        if (status && volume >= 3)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
/*
【問題概要 / 問題文要約】
■ 状態
- 音量 volume は初期 0
- 曲 state は初期「停止中」(playing = false)
■ 操作 (全 Q 回, i=1..Q)
Ai = 1 : 音量を 1 上げる (volume++)
Ai = 2 : volume >= 1 なら 1 下げる (volume--)
        volume == 0 なら 何もしない
Ai = 3 : 再生/停止をトグルする
        停止中 -> 再生中
        再生中 -> 停止中
■ 各 i 回目の操作直後に判定すること
- 「音量が 3 以上」かつ「曲が再生中」なら YES
- それ以外は NO
■ 制約
- 1 <= Q <= 2 * 10^5
- Ai ∈ {1, 2, 3}
 *https://atcoder.jp/contests/abc442/tasks/abc442_b
*/