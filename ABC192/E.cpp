#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll tim[100001];
vector< vector< tuple<int,ll,ll> > > to(100001);

ll solve() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  X--; Y--;
  REP(i,M) {
    int a,b; ll t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    to[a].emplace_back(b,t,k);
    to[b].emplace_back(a,t,k);
  }
  REP(i,N) tim[i] = 1123456789012LL;
  priority_queue< pair<ll, int> > q;
  q.emplace(0,X);
  tim[X] = 0;
  while( !q.empty()) {
    auto v = q.top(); q.pop();
    int city = v.second;
    if (city == Y) {
      cout << tim[Y] << endl;
      return tim[Y];
    }
    for( auto nv : to[city] ) {
      int ncity; ll nt,nk,nnt;
      tie(ncity, nt, nk) = nv;
      nnt = tim[city] + nt + (nk - (tim[city]%nk)) % nk;
      if ( tim[ncity] <= nnt ) continue;
      tim[ncity] = nnt;
      q.emplace(nnt, ncity);
    }
  }
  if (tim[Y] == 1123456789012LL ) {
    return -1;
  } else {
    return tim[Y];
  }
}

int main(){
  cout << solve() << endl;
}
