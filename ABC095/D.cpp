#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N,C;
  cin >> N >> C;
  vector< pair<ll,ll> > s;
  vector<ll> cal(N,0);
  vector<ll> cal_r(N,0);
  vector<ll> cmax(N,0);
  vector<ll> cmax_r(N,0);
  ll ans = 0;
  REP(i,N) {
    ll x, v;
    cin >> x >> v;
    s.emplace_back(x,v);
    if ( i == 0 )  cal[i] = v-x;
    else  cal[i] = cal[i-1] + v-(x-s[i-1].first);
    ans = max(ans, cal[i]);
    cmax[i] = ans;
  }
  cal_r[0] = s[N-1].second - (C - s[N-1].first);
  cmax_r[0] = cal_r[0];
  for( int i=1;i<N;++i) {
    cal_r[i] = cal_r[i-1] + s[N-1-i].second - (s[N-i].first - s[N-1-i].first);
    cmax_r[i] = max(cmax_r[i-1], cal_r[i]);
    ans = max(ans, cmax_r[i]);
  }
//  REP(i,N) cout << i << " : " << cal[i] << " " << cmax[i] << endl;
//  REP(i,N) cout << i << " : " << cal_r[i] << " " << cmax_r[i] << endl;
  // ‡•ûŒü‚É i+1 s‚Á‚Ä‚©‚çˆø‚«•Ô‚·ê‡
  REP(i,N-1) {
    ll cal_t = cal[i] - s[i].first + cmax_r[N-1-(i+1)];
    ans = max(cal_t, ans);
//    cout << i << " : " << cal_t << endl;
  }
  // ‹t•ûŒü‚É i+1 s‚Á‚Ä‚©‚çˆø‚«•Ô‚·ê‡
  REP(i,N-1) {
    ll cal_t = cal_r[i] - (C-s[N-1-i].first) + cmax[N-1-(i+1)];
    ans = max(cal_t, ans);
//    cout << i << " : " << cal_t << endl;
  }
  cout << ans << endl;
}

