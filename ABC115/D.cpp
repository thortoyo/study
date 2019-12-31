#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;


ll L[50], P[50];

int main() {
  ll N,X;
  cin >> N >> X;
  L[0] = 1;
  P[0] = 1;
  for(ll i=1; i<N+1; ++i ) {
    L[i] = 3 + 2 * L[i-1];
    P[i] = 1 + 2 * P[i-1];
  }
  ll ans = 0;
  for(ll i=N; i>0; --i ) {
    if ( X == 1 ) {
      break;
    } else if ( X < L[i-1] + 1 ) {
      X = X - 1;
    } else if ( X == L[i-1] + 1 ) {
      ans += P[i-1] ;
      break;
    } else if ( X <= L[i-1] + 2 ) {
      ans += P[i-1] + 1;
      break;
    } else if ( X < 2*L[i-1] + 2 ) {
      X = X - (L[i-1]+2);
      ans += P[i-1] + 1;
    } else {
      ans += P[i];
      break;
    }
  }
  cout << ans << endl;
}

