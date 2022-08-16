#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int D[100005];
int C[100005];

int main() {
  int N;
  cin >> N;
  int dmax = 0;
  REP(i,N) {
    cin >> D[i];
    C[D[i]]++;
    dmax = max( dmax, D[i]);
  }
  ll ans = 1;
  if ( (C[0] != 1) || (D[0] != 0)) { cout << "0" << endl; return 0;}
  for (int i=1; i<dmax+1 ;++i ) {
    if ( C[i] == 0 ) { cout << "0" << endl; return 0;}
    REP( j, C[i] ) {
      ans = (ans * C[i-1]) % MOD;
    }
  }
  cout << ans << endl;
}
