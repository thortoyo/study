#include <bits/stdc++.h>
using namespace std;

// 選ぶのは (Ln,Rm) とする
// 左端（i=0 とする）はBのみ、必ず L になる
// 左端（i=0 とする）のWは2回反転が必要だけど、2回は無理なので、不可
// BW なら、i=1 は2回反転が必要なので、i=1 は L				LL
// BB なら、i=1 は1回反転が必要なので、i=1 は R				LR
// BWW なら、i=2 は2回反転が必要なので、i=2 は R			LLR
// BWB なら、i=2 は1 or 3回反転が必要なので、i=2 は L			LLL
// BBB なら、i=2 は1 or 3回反転が必要なので、i=2 は L			LRL
// BBW なら、i=2 は2回反転が必要だけど、対象となるペアが左に存在しないので、不可
// BWWB なら、i=3 は奇数反転が必要なので、R				LLRR
// BWWW なら、i=3 は偶数回反転が必要なので、L				LLRL
// BWBB なら、i=3 は奇数回反転が必要なので、L				LLLR
// BWBW なら、i=3 は偶数回反転が必要なので、R				LLLL
// BBBB なら、i=3 は奇数回反転が必要なので、R				LRLR
// BBBW なら、i=3 は偶数回反転が必要なので、L				LRLL

// 左  現
// 偶  B	L
// 偶  W	R
// 奇  B	R
// 奇  W	L
// 左の L数-R数 == 0 なら R は選べない

// LRが決まったら、その組み合わせの数を数える。
// 

const int64_t MOD = 1000000007;

int main() {
  int64_t cnt = 1;
  int N;
  string S;
  cin >> N >> S;
  int ln = 1, rn = 0;
  N = N * 2;
  for(int i=1;i<N;++i) {
    if( S[i] == 'B' ) {
      if ( (ln - rn) % 2 == 1 ) {
        // R
        rn++;
        if ( ln-rn < 0 ) break;
        cnt = cnt * (ln-rn+1) % MOD;
//        cout << "ODD  B : R : " << cnt << endl;
      } else {
        // L
        ln++;
//        cout << "EVEN B : L : " << cnt << endl;
      }
    } else {
      if ( (ln - rn) % 2 == 1 ) {
        // L
        ln++;
//        cout << "ODD  W : L : " << cnt << endl;
      } else {
        // R
        rn++;
        if ( ln-rn < 0 ) break;
        cnt = cnt * (ln-rn+1) % MOD;
//        cout << "EVEN W : R : " << cnt << endl;
      }
    }
  }
  if ( ln-rn != 0 ){
    cnt = 0;
  } else {
    for(int i=1;i<N/2+1;i++ ) cnt = cnt * i % MOD;
  }
  cout << cnt << endl;

}
