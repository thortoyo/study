#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll solve() {
  ll ans = 0;
  int N;
  cin >> N;
  vector< tuple<int, int, int> > hen(N-1);
  REP(i,N-1) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    hen.emplace_back( w, u, v );
  }
  sort(hen.begin(), hen.end() );
  dsu dsu(N);
  for ( auto nh: hen ) {
    int u,v,w;
    tie(w,u,v) = nh;
    ans += ((ll)dsu.size(u) * (ll)dsu.size(v) * (ll)w);
    dsu.merge(u,v);
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
