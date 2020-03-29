#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,C;
  cin >> N >> C;
  vector< vector<int> > D(C, vector<int>(C));
  REP(i,C) REP(j,C)  cin >> D[i][j];
  vector< vector< int > > c(3);
  REP(i,N) REP(j,N) {
    int a;
    cin >> a;
    c[(i+j+2)%3].push_back( --a );
  }
//  for (auto a : c[0] ) cout << a << " "; cout << endl;
//  for (auto a : c[1] ) cout << a << " "; cout << endl;
//  for (auto a : c[2] ) cout << a << " "; cout << endl;
  vector< vector< ll > > tc(3, vector<ll>(C,0) );
  REP(i,3)
    REP(j,C) {
      int cost = 0;
      for ( auto a : c[i] ) cost += D[a][j];
//      cout << i << " " << j << " : " << cost << endl;
      tc[i][j] = cost;
    }
  ll ans = 500*500*2000;
  REP(i,C) REP(j,C) REP(k,C) {
    if ( i == j || j ==  k || i == k ) continue;
    ans = min( tc[0][i] + tc[1][j] + tc[2][k], ans ) ;
  }
  
  cout << ans << endl;

}

