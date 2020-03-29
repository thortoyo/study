#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int dp[105][105];

int main() {
  int H,W;
  cin >> H >> W;
  vector< string > S(H+1);
  REP(i,H) {
    cin >> S[i+1];
    S[i+1] = "." + S[i+1];
  }
  REP(i,W+1)  S[0][i] = '.';

  REP(i,W+1)  dp[0][i] = 100000;
  REP(i,H+1)  dp[i][0] = 100000;
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[1][0] = 0;
  for( int i=1; i<H+1; i++ ) {
    for( int j=1; j<W+1; j++ ) {
      dp[i][j] = min( (S[i][j] == S[i-1][j]) ? dp[i-1][j] : dp[i-1][j]+1,
                      (S[i][j] == S[i][j-1]) ? dp[i][j-1] : dp[i][j-1]+1 );
    }
  }
  if (S[H][W] == '#' ) dp[H][W]++;
  int ans = dp[H][W] / 2 + (dp[H][W]%2);
  cout << ans << endl;

//  REP(i,H+1) {
//    REP(j,W+1){
//      if ( dp[i][j] == 100000 ) cout << "* ";
//      else cout << dp[i][j] << " ";
//    }
//    cout << endl;
//  }
}


