#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];
  ll ans = 1LL << 32;
  REP(i, (1<<(N-1)) ) {
    ll x = 0;
    ll o = 0;
    REP(j,N) {
      o |= A[j];
      if ( (i & (1 << j)) == 0 ) {
        x ^= o;
        o = 0;
      }
    }
    ans = min(ans, x);
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
