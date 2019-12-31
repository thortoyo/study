#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  ll N,K,R,S,P;
  string tt;
  cin >> N >> K;
  cin >> R >> S >> P;
  cin >> tt;
  vector< ll > T(100005,0);
  REP(i,N) {
    ll ten;
    if ( tt[i] == 'r' )
      ten = P;
    else if ( tt[i] == 's' )
      ten = R;
    else
      ten = S;
    T[i] = ten;
  }
  ll ans = 0;
  REP(i,N) {
    if( (i >= K) && (tt[i-K] == tt[i]) ) {
      tt[i] = 'a';
      T[i] = 0;
    }
    ans += T[i];
//  cout << T[i][j] << endl;
  }
  cout << ans << endl;
}
