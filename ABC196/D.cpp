#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// cur[i][j]  現在の列の情報。Aをi個使っていて、jの形をしている
ll dp[16][16][8][70000];

ll solve() {
  int A,B,H,W;
  cin >> H >> W >> A >> B;
  dp[0][0][0][0] = 1;
  REP(y,H) {
    REP(x,W) {
      REP(i,A+1) {
        REP(j,(1 << W)) {
          if ( (j & (1<<x)) || (i >= A)) {
            // 置けない
            if ( x+1 >= W ) 
              dp[y+1][0][i][j & (~(1<<x))] += dp[y][x][i][j];
            else
              dp[y][x+1][i][j & (~(1<<x))] += dp[y][x][i][j];
          } else {
            // tate
            if ( y < H-1 ) {
              if ( x+1 >= W ) 
                dp[y+1][0][i+1][j | (1<<x)] += dp[y][x][i][j];
              else
                dp[y][x+1][i+1][j | (1<<x)] += dp[y][x][i][j];
            }
            // yoko
            if ( (x < W-1) && ((j & (1<<(x+1))) == 0) ) 
              dp[y][x+1][i+1][j | (1<<(x+1))] += dp[y][x][i][j];
            // hanjo
            if ( x+1 >= W )
              dp[y+1][0][i][j & (~(1<<x))] += dp[y][x][i][j];
            else
              dp[y][x+1][i][j & (~(1<<x))] += dp[y][x][i][j];
          }
        }
      }
    }
  }
  REP(y,H) {
    cout << "Y : " << y;
    REP(x,W) {
      cout << "  X : " << x;
      REP(i,A+1) {
        cout << "  i : " << i << endl;
        REP(j,(1 << W)) {
          cout << dp[y][x][i][j] << " ";
        }
        cout << endl;
      }
    }
  }
  
  return dp[H-1][W-1][A][(1<<W)-1];
}

int main(){
  cout << solve() << endl;
}
