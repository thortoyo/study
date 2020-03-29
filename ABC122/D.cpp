#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = pow(10,9) + 7;

// dp[i][0] : i•¶Žš–Ú‚ªA
// dp[i][1] : i•¶Žš–Ú‚ªG
// dp[i][2] : i•¶Žš–Ú‚ªC
// dp[i][3] : i•¶Žš–Ú‚ªT
ll dp[105][4][4][4];

// NG•¶Žš—ñ
// AGC, GAC, ACG, A*GC. AG*C
int main() {
  int N;
  cin >> N;
  int A = 0;
  int G = 1;
  int C = 2;
  int T = 3;

  REP(j,4) REP(k,4) REP(l,4) {
    if ( j == A && k == G && l == C ) continue;
    if ( j == A && k == C && l == G ) continue;
    if ( j == G && k == A && l == C ) continue;
    dp[2][j][k][l] = 1;
  }
  
  for(int i=2;i<N-1;i++) {
    REP(j,4) REP(k,4) REP(l,4) REP(m,4) {
      if ( j == A && k == G && m == C ) continue;
      if ( j == A && l == G && m == C ) continue;
      if ( k == G && l == A && m == C ) continue;
      if ( k == A && l == G && m == C ) continue;
      if ( k == A && l == C && m == G ) continue;
      dp[i+1][k][l][m] = (dp[i+1][k][l][m] + dp[i][j][k][l]) % MOD;
    }
  }
  
  ll ans = 0;
  REP(j,4) REP(k,4) REP(l,4) {
    ans = (ans + dp[N-1][j][k][l]) % MOD;
  }
  cout << ans << endl;
}

