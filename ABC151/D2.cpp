#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> NODE;

const int DINF = 100000;

vector< vector< vector< pair<int,int> > > > G(22, (vector< vector< pair<int,int> > >)(22) );
vector< vector< int > > d(22, (vector<int>)(22, DINF) );

int main() {
  int H,W;
  string sin;
  cin >> H >> W;
  vector< string > S;
  sin = "";
  REP(i, W+2) sin += '#';
  S.push_back(sin);
  REP(i, H) {
    cin >> sin;
    S.push_back( '#' + sin + '#');
  }
  sin = "";
  REP(i, W+2) sin += '#';
  S.push_back(sin);

  // グラフ作成
  REPI(y,1,H+2) REPI(x,1,W+2) {
    if (S[y][x] == '.' ) {
      if (S[y-1][x] == '.' ) G[y][x].emplace_back(y-1, x);
      if (S[y][x-1] == '.' ) G[y][x].emplace_back(y, x-1);
      if (S[y+1][x] == '.' ) G[y][x].emplace_back(y+1, x);
      if (S[y][x+1] == '.' ) G[y][x].emplace_back(y, x+1);
    }
  }
  int dmax = 0;
  // 各開始点からダイクストラ
  REPI(y,1,H+2) REPI(x,1,W+2) {
    if (S[y][x] == '.' ) {
      priority_queue< tuple< int, int, int > > q;
      q.emplace(  0, y, x );
      
      while ( !q.empty() ) {
        int n,ix,iy;
        tie(n,iy,ix) = q.top(); q.pop();
        d[iy][ix] = n;
        for ( auto nv : G[iy][ix] ) {
          int ny = nv.first;
          int nx = nv.second;
          if ( d[ny][nx] > n+1 )
            q.emplace( n+1, ny, nx );
        }
      }
      REPI(iy,1,H+2) REPI(ix,1,W+2) {
        if ( d[iy][ix] != DINF ) dmax = max(dmax, d[iy][ix] );
         d[iy][ix] = DINF;
      }
    }
  }
  cout << dmax << endl;

}
