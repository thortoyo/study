#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector< ll > A(N);
  vector< ll > c(60,0);
  REP(i,N) {
    cin >> A[i];
    REP(j,60) if( ((A[i] >> j) & 1)==1 ) c[j]++;
  }
  ll ans = 0;
  REP(j,60) {
    ll mux = (c[j] * (N - c[j])) % MOD;
    ll addn = (mux * ((1LL << j) % MOD)) % MOD;
    ans = (ans + addn) % MOD;
  }
  cout << ans << endl;

  return 0;
}
