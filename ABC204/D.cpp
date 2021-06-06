#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int dp[105][100005];


int solve() {
  int N, allt = 0;
  cin >> N;
  vector<int> T(N+1);
  REP(i,N) {
    cin >> T[i];
    allt += T[i];
  }
  dp[0][0] = 1;
  REP(i,N) {
    REP(j,100005) {
      if ( dp[i][j] != 0 ) {
        if ( j+T[i] <= 100000 )
          dp[i+1][j+T[i]] = dp[i][j];
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  int ans = allt / 2 + (allt%2);
  for ( ; dp[N][ans] == 0; ans++ );

  return ans;
}

int main(){
  cout << solve() << endl;
}
