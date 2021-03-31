#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// cur[i][j]  現在の列の情報。Aをi個使っていて、jの形をしている
ll dp[18][17][9][70000];

ll solve() {
  int A,B,H,W;
  cin >> H >> W >> A >> B;
  dp[0][0][0][0] = 1;
  REP(y,H+1) {
    REP(x,W) {
      REP(i,A+1) {
        if ((A-i)*2 > H*W-y*W+x) continue;
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
//          if ( dp[y][x][i][j] != 0 ) {
//            REP(iy,H) {
//              REP(ii,A+1) {
//                cout << "i " << ii << " : ";
//                for( int ix=W-1; ix>=0; ix-- ){
//                  REP(ij,(1 << W)) {
//                    cout << dp[iy][ix][ii][ij];
//                    if ( y == iy && x == ix && i == ii && j == ij ) cout << "*";
//                    else cout << " ";
//                  }
//                  cout << "  ";
//                }
//                cout << endl;
//              }
//              cout << endl;
//            }
//            cout << endl;
//          }
        }
      }
    }
  }
  // 全マスを埋めた次のマスで、畳枚数 A で、形がオール 0 なDPが答え
  // そのために、一行余計にDPを回している
  return dp[H][0][A][0];
}

int main(){
  cout << solve() << endl;
}
