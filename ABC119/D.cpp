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
  // Ai‚©‚çŒ©‚ÄAˆê”Ô‹ß‚¢ B ‚ğ’T‚·
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
  // Bi‚©‚çŒ©‚ÄAˆê”Ô‹ß‚¢ A ‚ğ’T‚·
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

  // Ai,Bi ‡‚í‚¹‚½”—ñ‚Ìˆê”Ô‹ß‚¢ŒÂŠ‚ğ’T‚·
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
