#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// imos法
// 区間のダメージをimos法を使って累積で求める。
// 範囲が広いので、モンスター位置で範囲を管理。
// 範囲に入っているかの判定は lower_bound で行う。

ll total[200020];

int main() {
  ll N,D,A;
  cin >> N >> D >> A;
  vector< pair<ll,ll> > mon(N);
  REP(i,N) {
    cin >> mon[i].first >> mon[i].second;
    mon[i].second = (mon[i].second+A-1) / A;
  }
  sort( mon.begin(), mon.end() );
  ll ans = 0;
  REP(i,N) {
    mon[i].second -= total[i];
    if ( mon[i].second > 0 ) {
      // 現在の累積ダメージが体力より低ければ、爆弾を置く
      total[i] += mon[i].second;
      ans += mon[i].second;
      // 爆弾範囲外になる最初のモンスター位置で、累積ダメージを引く
      auto it = lower_bound( mon.begin(), mon.end(), make_pair(mon[i].first+2*D+1, -1LL<<60));
      ll x = distance(mon.begin(), it);
      total[x] -= mon[i].second;
    }
    total[i+1] += total[i];
  }
  cout << ans << endl;
}
