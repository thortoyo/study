#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[2002][2002];

ll solve() {
  int H,W;
  cin >> H >> W;
  vector<string> A(2002);
  REP(y,H) cin >> A[y];
  REP(y,H) REP(x,W)
    if ((y+x)%2==0) {
      dp[y][x] = -40000000LL;
    } else {
      dp[y][x] = 40000000LL;
    }

  dp[H-1][W-1] = 0;
  for( int y=H-1; y>=0; y-- ) {
    for( int x=W-1; x>=0; x-- ) {
      if ((y+x)%2==0) { // takahasi
        if ( y < H-1 )
          dp[y][x] = max(dp[y][x], dp[y+1][x] + ((A[y+1][x] == '+') ? 1 : -1));
        if ( x < W-1 )
          dp[y][x] = max(dp[y][x], dp[y][x+1] + ((A[y][x+1] == '+') ? 1 : -1));
      } else {
        if ( y < H-1 )
          dp[y][x] = min(dp[y][x], dp[y+1][x] + ((A[y+1][x] == '+') ? -1 : 1));
        if ( x < W-1 )
          dp[y][x] = min(dp[y][x], dp[y][x+1] + ((A[y][x+1] == '+') ? -1 : 1));
      }
    }
  }
//  REP(y,H) {
//    REP(x,W) {
//      cout << dp[y][x] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;

  return dp[0][0];
}

int main(){
  ll ans = solve();
  if (ans==0) cout << "Draw" << endl;
  else if (ans>0) cout << "Takahashi" << endl;
  else  cout << "Aoki" << endl;

}
