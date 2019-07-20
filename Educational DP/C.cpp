#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<int> a(100002,0), b(100002,0), c(100002,0);
  vector< vector<int> > dp(100002,vector<int>(3,0));
  
  cin >> N;
  for (int i=0;i<N;++i ) {
    cin >> a[i] >> b[i] >> c[i];
  }
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  // ”z‚éDP
  for (int i=0;i<N-1;++i){
    dp[i+1][0] = max( dp[i+1][0], dp[i][1]+a[i+1] );
    dp[i+1][0] = max( dp[i+1][0], dp[i][2]+a[i+1] );
    dp[i+1][1] = max( dp[i+1][1], dp[i][0]+b[i+1] );
    dp[i+1][1] = max( dp[i+1][1], dp[i][2]+b[i+1] );
    dp[i+1][2] = max( dp[i+1][2], dp[i][0]+c[i+1] );
    dp[i+1][2] = max( dp[i+1][2], dp[i][1]+c[i+1] );
  }
  cout << max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])) << endl;
  // ‚à‚ç‚¤DP
  for (int i=1;i<N;++i){
    dp[i][0] = max( dp[i][0], dp[i-1][1]+a[i] );
    dp[i][0] = max( dp[i][0], dp[i-1][2]+a[i] );
    dp[i][1] = max( dp[i][1], dp[i-1][0]+b[i] );
    dp[i][1] = max( dp[i][1], dp[i-1][2]+b[i] );
    dp[i][2] = max( dp[i][2], dp[i-1][0]+c[i] );
    dp[i][2] = max( dp[i][2], dp[i-1][1]+c[i] );
  }
  cout << max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])) << endl;
}
