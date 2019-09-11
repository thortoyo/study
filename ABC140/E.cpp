#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<pair<int,int> > a(N);
  REP(i,N) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  ll ans = 0;

  multiset<int> s;
  s.emplace(-1);
  s.emplace(-1);
  s.emplace(N);
  s.emplace(N);

//  for ( auto x: a)
//    cout << x.first << " " << x.second << endl;

  REP(i,N) {
    int idx = a[i].second;
    auto it = s.lower_bound(idx);
    ll r1 = *it; it++;
    ll r2 = *it;
    it--; it--;
    ll l1 = *it; it--;
    ll l2 = *it;
    ans += ((ll)((r2-r1) * (idx-l1)) + (ll)((r1-idx) * (l1-l2))) * (ll)a[i].first;
//    cout << idx << ":" << l2 << ", " << l1 << " - " << r1 <<  ", " << r2;
//    cout << " * " << a[i].first << " => " << ((ll)((r2-r1) * (idx-l1)) + (ll)((r1-idx) * (l1-l2))) * (ll)a[i].first << endl;
    s.emplace(idx);
  }
  cout << ans << endl;

}


