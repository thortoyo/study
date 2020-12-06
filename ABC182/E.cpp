#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int light[1502][1502];
int blk[1502][1502];
int ans0[1502][1502];
int ans1[1502][1502];

int main(){
  int H,W,N,M;
  cin >> H >> W >> N >> M;
  REP(i,N) {
    int a,b;
    cin >> a >> b;
    light[a][b] = 1;
    ans0[a][b] = 1;
    ans1[a][b] = 1;
  }
  REP(i,M) {
    int c,d;
    cin >> c >> d;
    blk[c][d] = 1;
  }
  
  REP(y,H+2) {
    blk[y][0] = 1;
    blk[y][W+1] = 1;
  }
  REP(x,W+2) {
    blk[0][x] = 1;
    blk[H+1][x] = 1;
  }
  REP(y,H+2) {
    // ¨•ûŒü
    for(int x=1; x<=W; x++ ) {
      if (blk[y][x] == 0) ans0[y][x] |= ans0[y][x-1];
    }
    // ©•ûŒü
    for(int x=W; x>0; x-- ) {
      if (blk[y][x] == 0) ans0[y][x] |= ans0[y][x+1];
    }
  }
  REP(x,W+2) {
    // «•ûŒü
    for(int y=1; y<=H; y++ ) {
      if (blk[y][x] == 0) ans1[y][x] |= ans1[y-1][x];
    }
    // ª•ûŒü
    for(int y=H; y>0; y-- ) {
      if (blk[y][x] == 0) ans1[y][x] |= ans1[y+1][x];
    }
  }
  int ans = 0;
  REP(y,H+2) {
    REP(x,W+2) {
      if ((ans0[y][x] == 1) || (ans1[y][x] == 1)) ans++;
      }
  }
  cout << ans << endl;

}
