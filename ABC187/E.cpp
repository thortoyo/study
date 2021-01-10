#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

const ll INF = 10000000000000000LL;

void solve() {
  int N,Q;
  cin >> N;
  vector<ll> c(N, INF);
  vector< pair<int, int> > hen(N);
  vector< vector< int > > G(N);
  map< pair<int,int>, pair<ll,ll> > henx;
  REP(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    hen[i] = { a, b };
    G[a].emplace_back( b );
    G[b].emplace_back( a );
  }
  cin >> Q;
  REP(i,Q) {
    ll t,e,x;
    cin >> t >> e >> x;
    e--;
    int v, notv;
    if (t==1) {
      v = hen[e].first;
      notv = hen[e].second;
    } else {
      v = hen[e].second;
      notv = hen[e].first;
    }
    henx[ {v, notv} ].first += x;
    henx[ {notv, v} ].second += x;
  }
  ll allx = 0;

  queue< int > q;
  q.emplace( 0 );
  c[0] = 0;
  while( !q.empty() ) {
    auto v = q.front(); q.pop();
    for ( auto nv : G[v] ) {
      if (c[nv] != INF) continue;
      allx += henx[ {v, nv} ].first;
      c[nv] = c[v];
      c[nv] -= henx[ {v, nv} ].first;
      c[nv] += henx[ {v, nv} ].second;
      q.push(nv);
    }
  }
  REP(i,N) cout << c[i] + allx << endl;
  return;
}

int main(){
  solve();
}
