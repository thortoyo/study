#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), F(N);
  ll totalA = 0;
  REP(i,N) {
    cin >> A[i];
    totalA += A[i];
  }
  REP(i,N) {
    cin >> F[i];
  }

  if ( totalA <= K ) {
    cout << "0" << endl;
    return 0;
  }

  sort( A.begin(), A.end() );
  sort( F.begin(), F.end(), greater<ll>() );

  ll smin_l = 1LL << 60;
  ll smin_s = -1;
  ll smin;

  while(smin_l-smin_s > 1) {
    smin = (smin_l + smin_s) / 2;
    ll k0 = K;
    bool ok=true;
//    printf("%lld\n",smin);
    REP(i,N) {
      ll dif = A[i] * F[i] - smin;
//      printf(" %d : %lld\n",i,dif);
      if ( dif > 0 ) {
        k0 -= A[i] - smin / F[i];
      }
      if ( k0 < 0 ) {
        ok = false;
        break;
      }
    }
    if (ok) smin_l = smin;
    else smin_s = smin;
//    printf(" - %lld - %lld - %lld -\n",smin_s,smin,smin_l);
  }

  cout << smin_l << endl;
}
