#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

vector< vector< vector< tuple<ll,int,int> > > > to(501*2, vector< vector< tuple<ll,int,int> > >(501));
int R,C;
ll A[501][501];
ll B[501][501];
ll cost[501*2][501];

ll solve() {
  cin >> R >> C;
  REP(y,R) REP(x,C-1) cin >> A[y][x];
  REP(y,R-1) REP(x,C) cin >> B[y][x];
  REP(y,R*2) REP(x,C) cost[y][x] = (1LL << 60);
  REP(y,R) REP(x,C) {
    if ( x < C-1 )
      to[y*2][x].emplace_back(A[y][x], y*2,x+1);
    if ( x > 0 )
      to[y*2][x].emplace_back(A[y][x-1], y*2,x-1 );
    if ( y < R-1 )
      to[y*2][x].emplace_back(B[y][x], y*2+2,x);
    if ( y > 0  ) {
      to[y*2][x].emplace_back(2, y*2-1,x);
      to[y*2-1][x].emplace_back(0, y*2-2,x);
      if ( y > 1 ) 
        to[y*2-1][x].emplace_back(1, y*2-3,x);
    }
  }
//  REP(y,R*2) REP(x,C) {
//    for( auto nv: to[y][x] ) {
//      ll nc; int nx,ny;
//      tie(nc,ny,nx) = nv;
//      printf("(%d,%d) -> %lld -> (%d,%d)\n",y,x,nc,ny,nx);
//    }
//  }

  priority_queue< tuple< ll, int, int >, vector< tuple< ll, int, int > > , greater< tuple< ll, int, int > > > q;
  cost[0][0] = 0;
  q.emplace(0,0,0);
  while( !q.empty() ) {
    ll c; int x,y;
    tie(c,y,x) = q.top(); q.pop();
//    printf("(%d,%d) : %lld\n",y,x,c);
    for ( auto nv: to[y][x] ) {
      ll nc; int nx,ny;
      tie(nc,ny,nx) = nv;
      if ( c + nc >= cost[ny][nx] ) continue;
      cost[ny][nx] = c + nc;
      q.emplace(c + nc, ny, nx );
//      printf(" + (%d,%d) : %lld\n",ny,nx,c+nc);
    }
  }
  return cost[(R-1)*2][C-1];
}

int main(){
  cout << solve() << endl;
}
