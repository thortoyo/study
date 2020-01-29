#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 10000 * 20005;

// dp[i]: 合計iダメージ以上になる場合の、最小コスト
ll dp[20005];

int main(){
  ll H,N;
  cin >> H >> N;
  vector< ll > A(N);
  vector< ll > B(N);
  REP(i,N) cin >> A[i] >> B[i];

  REP(i,20005) dp[i] = INF;
  dp[0] = 0;

    
  REP(i,H+1) REP(j,N) {
    dp[i+A[j]] = min(dp[i+A[j]], dp[i]+B[j]);
  }
  ll ans = INF;
  REP(i,10000) {
    ans = min( dp[i+H], ans);
  }
  cout << ans << endl;
}
