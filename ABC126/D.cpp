#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef int64_t ll ;

int ans[100005];

int main() {

  int N;
  cin >> N;
  vector< vector< pair<int,ll> > > to(N);
  REP(i,N-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    to[u].emplace_back( v, w );
    to[v].emplace_back( u, w );
    ans[i] = -1;
  }
  ans[N-1] = -1;
  queue<int> q;
  q.push(0);
  ans[0] = 0;
  while( !q.empty() ) {
    int v = q.front(); q.pop();
//    cout << " " << v << endl;
    for ( auto nv: to[v] ) {
//      cout << " -  " << nv.first << endl;
      if ( ans[nv.first] != -1 ) continue;
      if ( ans[v] == 0 ) {
        ans[nv.first] = (nv.second % 2==0) ? 0 : 1;
      } else {
        ans[nv.first] = (nv.second % 2==0) ? 1 : 0;
      }
      q.push( nv.first );
    }
  }
  REP(i,N)
    cout << ans[i] << endl;

}
