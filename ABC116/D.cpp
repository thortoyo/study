#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll k0num[100005];

int main() {
  ll N,K;
  cin >> N >> K;
  vector< pair<ll,ll> > S;
  REP(i,N) {
    ll a,b;
    cin >> a >> b;
    S.emplace_back( b, a );
  }
  sort(S.begin(), S.end() );
  reverse(S.begin(), S.end() );
  ll aji = 0;
  ll kind = 0;
  REP(i,K) {
    aji += S[i].first;
    if (k0num[S[i].second] == 0 ) kind++;
    k0num[S[i].second]++;
  }
  int s0_idx = K-1;
  int s1_idx = K;
  ll total = aji + kind * kind;
  ll max_total = total;
  REP(i,K) {
    if ( (s0_idx < 0) || (s1_idx>=N) ) break;
    // S0の中で、一番小さくて、種類が2以上なものが交換候補
    while ((s0_idx >= 0) && (k0num[ S[ s0_idx ].second ] < 2)) s0_idx--;
    // S1の中で、一番大きくて、S0での種類が0なものが交換候補
    while ((s1_idx < N) && (k0num[ S[ s1_idx ].second ] != 0)) s1_idx++;
    if ( (s0_idx < 0) || (s1_idx>=N) ) break;
    kind++;
    aji = aji - S[ s0_idx ].first + S[ s1_idx ].first;
    total = aji + kind * kind;
//    cout << s0_idx << " " << s1_idx << " : " << aji << " " << kind << " " << total << endl;
    max_total = max( max_total, total );
    k0num[ S[ s0_idx ].second ]--;
    k0num[ S[ s1_idx ].second ]++;
    s0_idx--; s1_idx++;
  }
  cout << max_total << endl;;
}

