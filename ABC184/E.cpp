#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

#define mk_xy(x,y) (y)*10000+(x)
#define mk_y(n) (n)/10000
#define mk_x(n) (n)%10000

int d[2010][2010];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

const int INF = 1000000001;

int main(){
  int H,W;
  cin >> H >> W;
  vector< string > s(H);
  REP(i,H) cin >> s[i];

  REP(y,H) REP(x,W) d[y][x] = INF;

  int sx,sy,gx,gy;
  vector< vector<int> > warp(2010, (vector<int>)(2010));
  vector< vector< int > > wa(30);
  REP(y,H) REP(x,W) warp[y][x] = -1;
  
  REP(y,H) REP(x,W) {
    if (s[y][x] == 'S') {
      sx = x; sy = y;
    } else if (s[y][x] == 'G') {
      gx = x; gy = y;
    } else {
      if ((s[y][x] >= 'a') && (s[y][x] <= 'z')) {
        int w = (int)(s[y][x] - 'a');
        wa[w].push_back(mk_xy(x,y));
      }
    }
  }

//  cout << sx << " " << sy << endl;
//  cout << gx << " " << gy << endl;

  queue< int > q;
  q.emplace( mk_xy(sx,sy) );
  d[sy][sx] = 0;

  // BFS
  while( !q.empty() ) {
    auto v = q.front(); q.pop();
    int x = mk_x(v);
    int y = mk_y(v);
//    cout << x << " " << y << endl;
    REP(i,4) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if ( nx<0 || nx>=W || ny<0 || ny>=H ) continue;
      if ( s[ny][nx] == '#' ) continue;
      if ( d[ny][nx] <= d[y][x]+1 ) continue;
      d[ny][nx] = d[y][x]+1;
      q.push( mk_xy(nx,ny) );
    }
    if ((s[y][x] >= 'a') && (s[y][x] <= 'z')) {
      int w = (int)(s[y][x] - 'a');
      for ( auto v : wa[w] ) {
        int nx = mk_x(v);
        int ny = mk_y(v);
        if ( d[ny][nx] <= d[y][x]+1 ) continue;
        d[ny][nx] = d[y][x]+1;
        q.push( mk_xy(nx,ny) );
      }
    }
  }
  if ( d[gy][gx] == INF ) d[gy][gx] = -1;

  cout << d[gy][gx] << endl;
}
