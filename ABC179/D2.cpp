#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 998244353;
ll dp[200020];

int main() {
  int N,K;
  cin >> N >> K;
  int l[10], r[10];
  REP(i,K) cin >> l[i] >> r[i];

  dp[1] = 1;
  dp[2] = -1;
  for( int i=1; i<=N; i++ ) {
    dp[i] = (dp[i] + dp[i-1]) % MOD;
    REP(j,K) {
      if ( i+l[j] <= N )
        dp[i+l[j]] = (dp[i+l[j]] + dp[i]) % MOD;
      if ( i+r[j]+1 <= N ) {
        dp[i+r[j]+1] = dp[i+r[j]+1] - dp[i];
        if (dp[i+r[j]+1] < 0) dp[i+r[j]+1] += MOD;
      }
    }
//    REP(i,N+1) cout << dp[i] << " ";
//    cout << endl;
  }
  cout << dp[N] << endl;
}
