#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef int64_t ll ;
const ll MOD = 1000000007;

ll dp[100010][13];

int main() {
  string S;

  cin >> S;

  dp[0][0] = 1;

  // dp[i][j]: i�����ڂ܂ł̐��l�ŁAmod13�� j �ł��鐔�l�̑���
  for ( int i=0; i<S.length(); ++i ) {
    for ( int j=0; j<13; ++j ) {
      // "?"�̏ꍇ�́A���̌��̐��l�� 0-9 �S�Ă̏ꍇ�Œ��ׂ�
      // ����ȊO�̐��l�̏ꍇ�́A���̐��l�̏ꍇ�̂ݒ��ׂ�
      for ( int n=0; n<10; ++n ) {
        if ( (S[i] != '?') && (S[i] != (n + '0')) ) continue;
        // AB �Ƃ��������񂾂Ƃ��āAA mod 13 �����m�̏ꍇ��
        // i ������₵���ꍇ�i���l�Ƃ��Ĉ��������E�Ɉ���₵���ꍇ�j�� mod13 ��
        // (A * 10 + B) mod 13 �Ōv�Z�ł���B
        // A mod 13 = Y �Ƃ���ƁA
        // ((A mod 13) * (10 mod 13) + (B mod 13)) mod 13 = (Y * 10 + B) mod 13
        // �ƂȂ�B�iB �� 0 �` 10 �Ȃ̂ŁA13�͒����Ȃ��j
        dp[i+1][(j * 10 + n) % 13] += dp[i][j];
//        dp[i+1][(j * 10 + n) % 13] %= MOD;
      }
//      dp[i+1][j] = dp[i+1][j] % MOD;
    }
    REP(j,13)  dp[i+1][j] %= MOD;
  }

  cout << (dp[S.length()][5]) << endl;
  
}
