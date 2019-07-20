#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,W;
  int64_t vmax = 101*1000;
  int64_t wmax = 1000000002;
  
  vector<int64_t> w(102,0),v(102,0);
  vector< vector<int64_t> > dp(101,vector<int64_t>(vmax,wmax));

  cin >> N >> W;
  for (int i=0;i<N;++i ) {
    cin >> w[i] >> v[i];
  }
  dp[0][0] = 0;
  dp[0][v[0]] = w[0];
  // ”z‚éDP
  for (int i=0;i<N-1;++i){
    for (int j=0;j<vmax;++j){
      dp[i+1][j] = min( dp[i+1][j], dp[i][j] );
      if ( dp[i][j]+w[i+1] <= W ) {
        dp[i+1][j+v[i+1]] = min( dp[i+1][j+v[i+1]], dp[i][j]+w[i+1] );
      }
    }
  }
  int64_t maxv = 0;
  for ( int64_t i=0;i<vmax;++i) {
    if ( dp[N-1][i] <= W ) {
      maxv = max( maxv, i );
    }
  }
  cout << maxv << endl;
}
