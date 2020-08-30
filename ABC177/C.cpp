#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  vector< ll > A(N), B(N);
  REP(i,N) {
    cin >> A[i];
    B[i] = A[i];
  }
  for( int i=N-1; i>0; i-- )  {
    B[i-1] = (B[i-1] + B[i]) % MOD;
  }

  ll ans = 0;
  for (int i=0; i<N-1; i++ ) {
    ans = (ans + (A[i] * B[i+1] % MOD)) % MOD;
  }

  cout << ans << endl;
}
