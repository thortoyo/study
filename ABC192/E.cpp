#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll tim[100001];
vector< vector< tuple<int,ll,ll> > > to(100001);
const ll INF = 112345678901234567LL;

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
  REP(i,N) tim[i] = INF;
  priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> >  > q;
  q.emplace(0,X);
  tim[X] = 0;
  while( !q.empty()) {
    auto v = q.top(); q.pop();
    int city = v.second;
//    cout << city << " : " << tim[city] << endl;
    if (city == Y) {
//      cout << tim[Y] << endl;
      return tim[Y];
    }
    for( auto nv : to[city] ) {
      int ncity; ll nt,nk,nnt;
      tie(ncity, nt, nk) = nv;
//      nnt = tim[city] + nt + (nk - (tim[city]%nk)) % nk;
//      nnt = nt + (tim[city]+nk-1)/nk*nk;
      ll timmod = tim[city]%nk;
      nnt = tim[city] + nt + (nk - ((timmod == 0) ? nk : timmod));
      if ( tim[ncity] <= nnt ) continue;
//      cout << "  + " << ncity << " : " << nnt << endl;
      tim[ncity] = nnt;
      q.emplace(nnt, ncity);
    }
  }
  if (tim[Y] == INF) {
    return -1;
  } else {
    return tim[Y];
  }
}

int main(){
  cout << solve() << endl;
}
