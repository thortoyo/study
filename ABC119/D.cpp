#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll A,B,Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B);
  map<ll,ll> st;
  REP(i,A) cin >> s[i];
  REP(i,B) cin >> t[i];
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  REP(i,A) {
    auto it = lower_bound( t.begin(), t.end(), s[i] );
    ll hi, tgt;
    if ( it == t.end() ) {
      tgt = *(--it) - s[i];
    } else {
      hi = *it;
      --it;
      if ( it == t.begin() ) tgt = hi - s[i];
      else tgt = min(hi-s[i], s[i]-*it);
    }
    cout << "A " << s[i] << " " << tgt << endl;
    st.emplace( s[i], tgt );
  }
  REP(i,B) {
    auto it = lower_bound( s.begin(), s.end(), t[i] );
    ll hi, tgt;
    if ( it == s.end() ) {
      tgt = *(--it) - t[i];
    } else {
      hi = *it;
      --it;
      if ( it == s.begin() ) tgt = hi - t[i];
      else tgt = min(hi-t[i], t[i]-*it);
    }
    st.emplace( s[i], tgt );
  }
  for( auto x: st )
    cout << x.first << " " << x.second <<endl;

  REP(i,Q) {
    ll x;
    cin >> x;
    auto it = st.lower_bound( x );
    ll hi, tgt;
    if ( it == st.end() ) {
      --it;
      tgt = it->first + it->second;
    } else {
      hi = it->first + it->second;
      --it;
      if ( it == st.begin() ) tgt = hi;
      else tgt = min(tgt, it->first + it->second);
    }
    cout << tgt << endl;
  }
  return 0;
}
