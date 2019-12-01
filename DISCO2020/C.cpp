#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector< vector<int> > g(301, vector<int>(301,-1) );

void setval( int x0, int y0, int x1, int y1, int val ) {
  for ( int y=y0; y<=y1; ++y ) {
    for ( int x=x0; x<=x1; ++x ) {
      g[y][x] = val;
    }
  }
}

int main() {
  int H,K,W;
  cin >> H >> W >> K;
  vector< string > s(H);
  REP(i,H) {
    cin >> s[i];
  }

  int x0 = 0;
  int y0 = 0;
  int n = 1;
  REP(y,H) {
    x0 = 0;
    REP(x,W) {
      if ( s[y][x] == '#' ) {
        setval(x0,y0, x,y,n++);
        x0 = x+1;
      }
    }
    if ( x0 != 0 && x0 != W ) {
      setval(x0,y0,W-1,y,n-1);
    }
    if ( x0 != 0 ) y0=y+1;
  }
  REP(y,H) {
    if ( g[y][0] == -1 )
      REP(x,W) g[y][x] = g[y-1][x];
  }
  REP(y,H) {
    REP(x,W) {
      cout << g[y][x];
      if ( x != W-1 ) cout << " ";
    }
    cout << endl;
  }
}
