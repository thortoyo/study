#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


ll dp[105][2][105];

int main() {
  string N;
  ll K;
  cin >> N >> K;
  dp[0][0][0] = 0;
  dp[0][0][1] = 1;
  dp[0][1][0] = 1;
  dp[0][1][1] = N[0]-'1';
  REP(i,N.length()+1) {
    REP(j,101) {
      dp[i+1][1][j+1] += dp[i][1][j] * 9;
      dp[i+1][1][j+1] += dp[i][0][j] * (N[i+1]-'0');
      dp[i+1][1][j]   += dp[i][1][j];
      dp[i+1][1][j]   += dp[i][0][j];
      if (N[i+1] == '0') {
        dp[i+1][0][j+1] = 0;
        dp[i+1][0][j]   = dp[i][0][j];
      } else {
        dp[i+1][0][j+1] = dp[i][0][j];
        dp[i+1][0][j]   = 0;
      }
    }
  }
  cout << (dp[N.length()-1][0][K] + dp[N.length()-1][1][K] ) << endl;

  REP(i,3) REP(j,3) REP(k,2) cout << "  [" << i << "][" << k  << "][" << j << "] : " <<  dp[i][k][j] << endl;
}

