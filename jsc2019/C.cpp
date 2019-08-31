#include <bits/stdc++.h>
using namespace std;

// �I�Ԃ̂� (Ln,Rm) �Ƃ���
// ���[�ii=0 �Ƃ���j��B�̂݁A�K�� L �ɂȂ�
// ���[�ii=0 �Ƃ���j��W��2�񔽓]���K�v�����ǁA2��͖����Ȃ̂ŁA�s��
// BW �Ȃ�Ai=1 ��2�񔽓]���K�v�Ȃ̂ŁAi=1 �� L				LL
// BB �Ȃ�Ai=1 ��1�񔽓]���K�v�Ȃ̂ŁAi=1 �� R				LR
// BWW �Ȃ�Ai=2 ��2�񔽓]���K�v�Ȃ̂ŁAi=2 �� R			LLR
// BWB �Ȃ�Ai=2 ��1 or 3�񔽓]���K�v�Ȃ̂ŁAi=2 �� L			LLL
// BBB �Ȃ�Ai=2 ��1 or 3�񔽓]���K�v�Ȃ̂ŁAi=2 �� L			LRL
// BBW �Ȃ�Ai=2 ��2�񔽓]���K�v�����ǁA�ΏۂƂȂ�y�A�����ɑ��݂��Ȃ��̂ŁA�s��
// BWWB �Ȃ�Ai=3 �͊���]���K�v�Ȃ̂ŁAR				LLRR
// BWWW �Ȃ�Ai=3 �͋����񔽓]���K�v�Ȃ̂ŁAL				LLRL
// BWBB �Ȃ�Ai=3 �͊�񔽓]���K�v�Ȃ̂ŁAL				LLLR
// BWBW �Ȃ�Ai=3 �͋����񔽓]���K�v�Ȃ̂ŁAR				LLLL
// BBBB �Ȃ�Ai=3 �͊�񔽓]���K�v�Ȃ̂ŁAR				LRLR
// BBBW �Ȃ�Ai=3 �͋����񔽓]���K�v�Ȃ̂ŁAL				LRLL

// ��  ��
// ��  B	L
// ��  W	R
// ��  B	R
// ��  W	L
// ���� L��-R�� == 0 �Ȃ� R �͑I�ׂȂ�

// LR�����܂�����A���̑g�ݍ��킹�̐��𐔂���B
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
