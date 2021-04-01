#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = (1LL << 62);

// f(x) = min(c, max(b, x+a))
//C = min(c, max(b,c0+a))
//B = max(b, b0+a)
//A = a0+a
// t = 1 の場合は、b = -INF, c = INF なので、
//	C = c0+a
//	B = b0+a
//	A = a0+a
// t = 2 の場合は、a = 0, c = INF なので、
//	C = max(b, c0)
//	B = max(b, b0)
//	A = a0
// t = 3 の場合は、a = 0, b = -INF なので、
//	C = min(c, c0)
//	B = b0
//	A = a0

void solve() {
  int N,Q;
  cin >> N;
  ll a, b, c, t;
  ll A = 0;
  ll B = -INF;
  ll C = INF;
  REP(i,N) {
    cin >> a >> t;
    if (t==1) {
      A += a;
      B += a;
      C += a;
    } else if (t==2) {
      B = max(B, a);
      C = max(C, a);
    } else {
      C = min(C, a);
    }
  }
  cin >> Q;
  REP(i,Q) {
    ll x;
    cin >> x;
    ll ans = min(C, max(B, x+A));
    cout << ans << endl;
  }
  return;
}

int main(){
  solve();
}
