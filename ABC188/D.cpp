#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(){
  ll N,C;
  cin >> N >> C;
  vector< pair<int,ll> > cost;
  REP(i,N) {
    int a,b; ll c;
    cin >> a >> b >> c;
    cost.emplace_back( a, c );
    cost.emplace_back( b+1, -c );
  }
  sort( cost.begin(), cost.end() );
  int day = 1;
  ll now = 0;
  ll ans = 0;
  REP(i,N*2) {
//    cout << day << " " << now << " " << ans << " : " << cost[i].first << " " << cost[i].second << endl;
    if ( now > C ) {
      ans += (cost[i].first - day) * C;
    } else {
      ans += (cost[i].first - day) * now;
    }
    now = now + cost[i].second;
    day = cost[i].first;
  }
  cout << ans << endl;
}
