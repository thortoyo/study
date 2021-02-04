#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// dp[i][j]: i”Ô–Ú‚Å Yi‚ª j ‚Å‚ ‚éê‡‚Ì‘g‚Ý‡‚í‚¹
ll dp[62][2];

ll solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  REP(i,N) cin >> S[i];
  dp[0][1] = 1;
  dp[0][0] = 1;
  REP(i,N) {
    if (S[i] == "AND") {
      dp[i+1][0] = dp[i][0] * 2 + dp[i][1];
      dp[i+1][1] = dp[i][1];
//      cout << "AND / ";
    } else {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1] * 2 + dp[i][0];
//      cout << "OR / ";
    }
//    cout << "Yi 0 : " << dp[i+1][0] << "  Yi 1 : " << dp[i+1][1] << endl;
  }
  return dp[N][1];
}

int main(){
  cout << solve() << endl;
}
