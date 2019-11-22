#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// H0 = 0 として、入力は H1 から始まるとする
// DP[i][j][k]： 1～i列の範囲で、j列採用した場合で、左の採用列の一番近い列が k の最小値
// DP[0][][] = 0
// 採用しない場合は変わらず
// 	DP[1][0][k] = DP[0][0][k]
// 採用する場合
// 	DP[1][1][1] = DP[0][0][0] + (H1 > H0) ? (H1 - H0) : 0
// 汎用化すると
// j <= i, k < i
// 採用しない場合
// 	DP[i][j][k] = min( DP[i-1][j][k], DP[i][j][k])
// 採用する場合
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
        // i列目を採用しない
        dp[i][j][k] = min( dp[i-1][j][k], dp[i][j][k]);
        if ( j > 0 ) {
          // i列目を採用する
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
