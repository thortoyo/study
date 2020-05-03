#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N,M,S;
  cin >> N >> M >> S;
  int amax = 2501;
  if (S >= amax) S = amax;
  vector< vector< tuple<ll,int, int> > > G(N);
  REP(i,M) {
    int u,v,a,b;
    cin >> u >> v >> a >> b;
    u--; v--;
    G[u].emplace_back( b, v, a);
    G[v].emplace_back( b, u, a);
  }
  vector<int> C(N);
  vector<ll> D(N);
  REP(i,N)  cin >> C[i] >> D[i];

  vector< vector<ll> > ti(N, vector<ll>(amax+2, 1LL << 62));
  priority_queue< tuple< ll, int, int >, vector< tuple< ll, int, int > > , greater< tuple< ll, int, int > > > q;
  q.push( {0, 0, S} );
  ti[0][S] = 0;
  while( !q.empty() ) {
    ll t; int v, co;
    tie(t,v,co) = q.top(); q.pop();
//    cout << t << " " << v << " " << co << endl;
    // —¼‘Ö
    if ( co < amax ) {
      int vco = min(co + C[v], amax);
      if ( ti[v][co] + D[v] < ti[v][vco] ) {
        ti[v][vco] = ti[v][co] + D[v];
        q.emplace( ti[v][vco], v, vco );
//      cout << "  add " << ti[v][co+C[v]] << " " << v << " " << vco << endl;
      }
    }
    for ( auto nv : G[v] ) {
      ll nvt; int nvpos, nvco;
      tie(nvt, nvpos, nvco) = nv;
      // ˆÚ“®
      if ( co >= nvco ) {
        if ( ti[v][co] + nvt < ti[nvpos][co-nvco] ) {
          ti[nvpos][co-nvco] = ti[v][co] + nvt;
          q.emplace( ti[nvpos][co-nvco], nvpos, co-nvco );
//        cout << "  add " << ti[nvpos][co-nvco] << " " << nvpos << " " << co-nvco << endl;
        }
      }
    }
  }
  for (int i=1; i<N; i++ ) {
    ll ans = 1LL << 62;
    REP(j, amax) {
      ans = min(ans, ti[i][j]);
    }
    cout << ans << endl;
  }

}
