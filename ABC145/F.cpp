#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// H0 = 0 �Ƃ��āA���͂� H1 ����n�܂�Ƃ���
// DP[i][j][k]�F 1�`i��͈̔͂ŁAj��̗p�����ꍇ�ŁA���̗̍p��̈�ԋ߂��� k �̍ŏ��l
// DP[0][][] = 0
// �̗p���Ȃ��ꍇ�͕ς�炸
// 	DP[1][0][k] = DP[0][0][k]
// �̗p����ꍇ
// 	DP[1][1][1] = DP[0][0][0] + (H1 > H0) ? (H1 - H0) : 0
// �ėp�������
// j <= i, k < i
// �̗p���Ȃ��ꍇ
// 	DP[i][j][k] = min( DP[i-1][j][k], DP[i][j][k])
// �̗p����ꍇ
// 	DP[i][j][i] = min( DP[i-1][j-1][k] + (Hi > Hk) ? (Hi - Hk) : 0, DP[i][j][i] )

ll dp[305][305][305];

const ll INF = 1LL << 60;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> H(N+1);
  H[0] = 0;
  REP(i,N) {
    cin >> H[i+1];
  }
  
  REP(i,N+1) REP(j,N+1) REP(k,N+1) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  
  for ( int i=1; i<N+1; ++i ) {
    REP(j,i+1) {
      REP(k,i) {
        // i��ڂ��̗p���Ȃ�
        dp[i][j][k] = min( dp[i-1][j][k], dp[i][j][k]);
        if ( j > 0 ) {
          // i��ڂ��̗p����
          dp[i][j][i] = min( dp[i-1][j-1][k] + ((H[i] > H[k]) ? (H[i] - H[k]) : 0), dp[i][j][i] );
        }
      }
    }
  }
  ll ans = INF;
  for ( int j=N-K; j<=N; ++j ){
    REP(k,N+1) {
      ans = min( ans, dp[N][j][k]);
    }
  }
//   REP(i,N+1) {
//     REP(j,N+1) {
//       REP(k,N+1) {
//         if ( dp[i][j][k] == INF ) 
//           cout << "***" << " ";
//         else
//           cout << setw(3) << dp[i][j][k] << " ";
//       }
//       cout << " : ";
//     }
//     cout << endl;
//   }

  cout << ans << endl;
}
