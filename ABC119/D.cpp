#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int main() {
  ll A,B,Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B);
  map<ll,ll> st;
  REP(i,A) cin >> s[i];
  REP(i,B) cin >> t[i];
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  // Aiから見て、一番近い B を探す
  REP(i,A) {
    auto it = lower_bound( t.begin(), t.end(), s[i] );
    ll hi, lo, tgt;
    if ( it == t.end() ) hi = INF;
    else hi = *it - s[i];
    if ( it == t.begin() ) lo = INF;
    else lo = s[i] - *(--it);
    tgt = min(hi,lo);
//    cout << "A " << s[i] << " " << tgt << " " << hi << " " << lo << endl;
    st.emplace( s[i], tgt );
  }
  // Biから見て、一番近い A を探す
  REP(i,B) {
    auto it = lower_bound( s.begin(), s.end(), t[i] );
    ll hi, lo, tgt;
    if ( it == s.end() ) hi = INF;
    else hi = *it - t[i];
    if ( it == s.begin() ) lo = INF;
    else lo = t[i] - *(--it);
    tgt = min(hi,lo);
//    cout << "B " << t[i] << " " << tgt << endl;
    st.emplace( t[i], tgt );
  }
//  for( auto x: st )
//    cout << x.first << " " << x.second <<endl;

  // Ai,Bi 合わせた数列の一番近い個所を探す
  REP(i,Q) {
    ll x;
    cin >> x;
    auto it = st.lower_bound( x );
    ll hi, lo, tgt;
    if ( it == st.end() ) hi = INF;
    else hi = it->first - x + it->second;
    if ( it == st.begin() ) lo = INF;
    else { --it; lo = x - it->first + it->second; }
    tgt = min(hi,lo);
    
    cout << tgt << endl;
  }
  return 0;
}
