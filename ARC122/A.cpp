#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint1000000007;

mint fib[100005];

void calc_fib() {
  fib[0] = 1;
  fib[1] = 1;
  for(int i=2;i<100002;i++) fib[i] = fib[i-1]+fib[i-2];
}
mint compute_fib(mint a, mint b, int n) {
  if (n==0) return a;
  if (n==1) return b;
  return( a*fib[n-2] + b*fib[n-1] );
}

mint solve() {
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  vector<mint> p(N+1),m(N+1);
  calc_fib();
  REP(i,N) cin >> A[i];
  p[0] = fib[N]; m[0] = 0;
  for(int i=1;i<N;i++) {
    p[i] = compute_fib( fib[i], fib[i]*2, N-i-1 );
    m[i] = compute_fib( fib[i-1], fib[i-1], N-i-1 );
  }
  mint ans = 0;
  REP(i,N) {
    ans += p[i] * A[i];
    ans -= m[i] * A[i];
  }
  return ans;
}

int main(){
  cout << solve().val() << endl;
}
