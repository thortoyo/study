#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

const int dx[4] = { 0,  0, -1, 1};
const int dy[4] = { 1, -1,  0, 0};
const int d2x[20] = {-1, 0, 1,-2,-1, 0, 1, 2,-2,-1, 1, 2,-2,-1, 0, 1, 2,-1, 0, 1};
const int d2y[20] = {-2,-2,-2,-1,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};

int dp[501][501];
vector< vector< vector< tuple<int,int,int> > > to(501, (vector< vector< tuple<int,int,int> > >(501)));

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> S(1000);
  REP(i,H) {
    string a;
    cin >> S[i];
  }
  dp[0][0] = 0;
  REP(y,H) {
    REP(x,W) {
      REP(d, 4) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if ( (ny < 0) || (nx < 0) || (ny >= H) || (nx >= W) ) continue;
        if ( S[ny][nx] == '.' ) 
          to[y][x].emplace_back(0,ny,nx);
      }
      REP(d, 20) {
        int ny = y + d2y[d];
        int nx = x + d2x[d];
        if ( (ny < 0) || (nx < 0) || (ny >= H) || (nx >= W) ) continue;
        to[y][x].emplace_back(1,ny,nx);
      }
    }
  }
  priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > q;
  q.push( {0, 0, 0} );
  dp[0][0] = 0;
  while( !q.emplty() ) {
    int c, ny, nx;
    tie(c, ny, nx) = q.top(); q.pop();
    for ( auto 

  return;
}

int main(){
  solve();
  cout << endl;
}
