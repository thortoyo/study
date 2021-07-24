#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

using mint = modint1000000007;

ll d[212345];
mint c[212345];

ll solve() {
  int N, M;
  cin >> N >> M;
  ll INF = 1LL << 62;
  REP(i,N) d[i] = INF;
  vector< vector<int> > G(N);
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  d[0] = 0;
  c[0] = 1;
  queue<int> q;
  q.push(0);
  while( !q.empty() ) {
    int v = q.front(); q.pop();
    for ( auto nv : G[v] ) {
      if ( d[nv] == d[v] + 1 ) {
        c[nv] += c[v];
      } else if ( d[nv] == INF ) {
        d[nv] = d[v] + 1;
        c[nv] = c[v];
        q.push(nv);
      }
    }
  }
  return c[N-1].val();
}

int main(){
  cout << solve() << endl;
}
