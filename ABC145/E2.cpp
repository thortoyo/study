// �Ō�ɐH�ׂ�̂� k �Ƃ��Ă݂�B
// ����ȊO�̂��̂���I���DP����MAX���o���� + Bi ������Ai�I������MAX���o��B
// ���̏����� k ��S���U��� O(N^2T) �ɂȂ��ĊԂɍ���Ȃ��B
//
// �ʏ��DP�ł́A���Ԃ�1���A�H�ׂ�A�H�ׂȂ��A���ꂼ��̏ꍇ��MAX�l��
// �X�V���Ă����B�Ȃ̂� i �Ԗڂ܂ŏ������i�񂾏ꍇ�́Ai �܂ł̂��̂̓��ōő�l�A���ł��Ă���B
// ����𗘗p����ƁAk ������O���̕����g���Ă�MAX�����łɋ��܂��Ă��邱�ƂɂȂ�B
// �Ȃ̂ŁA�c��� k �������������̕��������g����MAX�l��������΂����B
// ����� i ��傫������DP���X�V���Ă�����OK�B
// 
// ���ꂪ�ł���΁A����DP[k][t1] �� �~��DP[k][t2] �̍��v�ŁAk �ȊO���g�����ꍇ��MAX��������B
// t1 �� t2 �́At1 + t2 = T-1 �ƂȂ�΂����̂ŁA���Ԃ�U���đS���v�Z���čő�l������΂����B
// O(NT) �ŕ�����B

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll dp1[3005][3005];
ll dp2[3005][3005];

int main() {
  ll N, T;
  cin >> N >> T;
  vector<int> A(N), B(N);
  REP(i,N) {
    cin >> A[i] >> B[i];
  }
  REP(i,N) {
    int k = N-i-1;
    REP( ti, T ) {
      if ( ti >= A[i]) dp1[i+1][ti] = max(dp1[i][ti-A[i]] + B[i], dp1[i][ti] );
      else dp1[i+1][ti] = dp1[i][ti];
      if ( k > 0 ) {
        if ( ti >= A[k]) dp2[k-1][ti] = max(dp2[k][ti-A[k]] + B[k], dp2[k][ti] );
        else dp2[k-1][ti] = dp2[k][ti];
      }
    }
  }
  ll ans = 0;
  REP(i,N) {
    REP(j,T-1) {
      ans = max( ans, dp1[i][j] + dp2[i][T-1-j] + B[i] );
    }
  }
//  REP(i,T) {
//    REP(j,N+1) {
//      printf("%3d ",dp[j][i]);
//    }
//    cout << endl;
//  }

  cout << ans << endl;
}
