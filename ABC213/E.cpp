#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

//壁を壊すのが1x1なら、壁方向に進む時のコストを1にして、ダイクストラでOK
//この問題の場合2x2なので、壊した場合にコスト1で飛べる範囲
//
//壊す個所の候補
//	 x
//	x@x
//	 x
//
//2x2範囲で壊すので、例えば以下の様に4マスはコスト1で行けるようになる。
//	 xx
//	 xx
//	 @
//
//	xx
//	xx
//	 @
//
//	  xx
//	 @xx
//
//つまり以下の場所にコスト1で行く枝を張ればOK
//	 xxx
//	xxxxx
//	xx@xx
//	xxxxx
//	 xxx


const int dx[4] = { 0,  0, -1, 1};
const int dy[4] = { 1, -1,  0, 0};
const int d2x[20] = {-1, 0, 1,-2,-1, 0, 1, 2,-2,-1, 1, 2,-2,-1, 0, 1, 2,-1, 0, 1};
const int d2y[20] = {-2,-2,-2,-1,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};

int dp[501][501];
vector< vector< vector< tuple<int,int,int> > > > to(501, (vector< vector< tuple<int,int,int> > >(501)));

void dbgprint(int h, int w) {
  REP(y, h) {
    REP(x,w) {
      if (dp[y][x] == 1<<30) cout << "INF ";
      else printf("%3d ",dp[y][x]);
    }
    cout << endl;
  }
}

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

  REP(y, 501) REP(x,501) dp[y][x] = 1 << 30;
  
  priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > q;
  q.push( {0, 0, 0} );
  dp[0][0] = 0;
  while( !q.empty() ) {
    int c, y, x;
    tie(c, y, x) = q.top(); q.pop();
//    dbgprint(H, W);
    for ( auto ns : to[y][x] ) {
      int d, ny, nx;
      tie(d, ny, nx) = ns;
//      printf("%d,%d : %d %d,%d\n",x,y,d,nx,ny);
      if ( dp[ny][nx] > dp[y][x] + d ) {
        dp[ny][nx] = dp[y][x] + d;
        q.emplace( dp[ny][nx], ny, nx );
      }
    }
  }
  cout << dp[H-1][W-1] << endl;
  return;
}



int main(){
  solve();
}
