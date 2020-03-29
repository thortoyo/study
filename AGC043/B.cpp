#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


ll C[1000005];
int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<ll> A(N);
  A[0] = S[0] - '1';
  REP(i,N-1) {
    int a0 = (S[i]-'1');
    int a1 = (S[i+1]-'1');
    A[i+1] = A[i] + abs(a0-a1);
  }
  C[0] = 1;
  REP(i,N-1) {
    C[i+1] = C[i] * (N-1-i) / (i+1);
  }
  REP(i,N) {
    C[i] %= 3;
  }
    
  ll ans = 0;
  bool flg = true;
  for( int i=N-1; i>=0; --i ) {
    if ( flg ) {
      ans += (A[i] * C[i]) % 3;
//      cout << ans << " " << A[i] << " " << C[i] << " " << (A[i] * C[i] % 3) << endl;
      flg = false;
    } else {
      ans -= (A[i] * C[i]%3);
      if ( ans < 0 ) ans += 3;
      flg = true;
    }
//  cout << ans << endl;
  }
  cout << ans << endl;
}


