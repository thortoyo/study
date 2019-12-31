#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int main() {
  ll N,K;
  cin >> N >> K;
  vector<ll> h(N);
  REP(i,N) {
    cin >> h[i];
  }
  sort( h.begin(), h.end() );
  ll ans = INF;
  REP(i,N-K+1) {
    ans = min( h[i+K-1] - h[i], ans );
  }
  cout << ans << endl;
}

