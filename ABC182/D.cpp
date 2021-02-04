#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), ra(N+5,0),rra(N+5,0);
  REP(i,N) cin >> A[i];
  ra[0] = A[0];
  rra[0] = A[0];
  for(int i=1;i<N;i++) ra[i] = ra[i-1] + A[i];
  for(int i=1;i<N;i++) rra[i] = rra[i-1] + ra[i];
  ll ramax = max(0LL, A[0]);
  ll ans = max(0LL, A[0]);
  REP(i,N-1) {
    ramax = max(ramax, ra[i+1]);
    ans = max(ans, rra[i]+ramax);
//    cout << " " << ans << " " << ramax << " " << rra[i] <<endl;
  }
  cout << ans << endl;
}
