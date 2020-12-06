#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

char m[2002][2002];
ll t[2002][2002];
ll tu[2002][2002]; // ã•ûŒü‡Œv
ll tl[2002][2002]; // ¶•ûŒü‡Œv
ll tn[2002][2002]; // ¶ã•ûŒü‡Œv
ll MOD = 1000000007;

int main(){
  int H,W;
  cin >> H >> W;
  REP(y,H+2) m[y][0] = '#';
  REP(y,H+2) m[y][W+1] = '#';
  REP(x,W+2) m[0][x] = '#';
  REP(x,W+2) m[H+1][x] = '#';
  REP(y,H) {
    REP(x,W) {
      cin >> m[y+1][x+1];
    }
  }
  t[1][1] = 1;
  tu[1][1] = 1;
  tl[1][1] = 1;
  tn[1][1] = 1;
  for(int y=1;y<=H;y++) {
    for(int x=1;x<=W;x++) {
      if (y==1 && x==1) continue;
      if (m[y][x] == '#' ) continue;
      t[y][x] = (tu[y-1][x] + tl[y][x-1] + tn[y-1][x-1]) % MOD;
      tu[y][x] = (t[y][x] + tu[y-1][x]) % MOD;
      tl[y][x] = (t[y][x] + tl[y][x-1]) % MOD;
      tn[y][x] = (t[y][x] + tn[y-1][x-1]) % MOD;
    }
  }
  cout << t[H][W] << endl;
}
