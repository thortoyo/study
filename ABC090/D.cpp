#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// a = bx + KˆÈã
// K >= a - bx
// b > K

int main() {
  int N,K;
  cin >> N >> K;
  ll ans = 0;
  for ( int b=K+1;b<=N;b++ ) {
    ans += (N / b) * (b-K);
//    cout << b << " : " << ans << endl;
    if ( N%b != 0 && N%b >= K ) ans += N%b - (K- ((K==0) ? 0: 1));
//    cout << b << " : " << ans << endl;
  }
  cout << ans << endl;
}

