#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int h[10002];
  int dp[10002];
  cin >> N;
  for (int i=0;i<N;i++ ) {
    cin >> h[i];
    dp[i] = 0;
  }
  dp[1] = abs(h[1] - h[0]);
  for (int i=2;i<N;++i){
    dp[i] = min( dp[i-1]+abs(h[i] - h[i-1]), dp[i-2]+abs(h[i]-h[i-2]) );
  }
  cout << dp[N-1] << endl;
}
