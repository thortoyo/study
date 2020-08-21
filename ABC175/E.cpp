#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// dp[i][j][k] : i行目、j列目で、現在の行で k 個拾った場合の価値の合計
ll dp[3003][3003][4];
ll val[3003][3003];

int main(){
  int R,C,K;
  cin >> R >> C >> K;
  REP(i,K) {
    int r,c;
    ll v;
    cin >> r >> c >> v;
    r--, c--;
    val[r][c] = v;
  }
  dp[0][0][1] = val[0][0];
  REP(i,R) REP(j,C) REP(k,4) {
    dp[i+1][j][0] = max( dp[i+1][j][0], dp[i][j][k] );
    dp[i+1][j][1] = max( dp[i+1][j][1], dp[i][j][k] + val[i+1][j] );
    dp[i][j+1][k] = max( dp[i][j+1][k], dp[i][j][k] );
    if ( k != 3 )
      dp[i][j+1][k+1] = max( dp[i][j+1][k+1], dp[i][j][k] + val[i][j+1] );
  }
  ll ans = 0;
  REP(i,4) ans = max( ans, dp[R-1][C-1][i] );
/*  
  REP(i,4) {
    REP(j,4) {
      cout << val[i][j] << " ";
    }
    cout << endl;
  }
  REP(i,4) {
    REP(j,4) {
      REP(k,4) cout << dp[i][j][k] << " ";
      cout << "  ";
    }
    cout << endl;
  }
  */
  cout << ans << endl;
}
