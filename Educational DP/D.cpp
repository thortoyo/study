#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,W;
  vector<int> w(102,0),v(102,0);
  vector< vector<int64_t> > dp(101,vector<int64_t>(100001,0));
  
  cin >> N >> W;
  for (int i=0;i<N;++i ) {
    cin >> w[i] >> v[i];
  }
  dp[0][w[0]] = v[0];
  // ”z‚éDP
  for (int i=0;i<N-1;++i){
    for (int j=0;j<W;++j){
      dp[i+1][j] = max( dp[i+1][j], dp[i][j] );
      if ( j+w[i+1] <= W ) {
        dp[i+1][j+w[i+1]] = max( dp[i+1][j], dp[i][j]+v[i+1] );
      }
    }
  }
  int64_t maxv = 0;
  for ( int i=0;i<W+1;++i) {
   maxv = max( maxv, dp[N-1][i] );
  }
  cout << maxv << endl;
}
