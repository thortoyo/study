#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  int h[100102];
  int64_t dp[100102];
  cin >> N >> K;
  for (int i=0;i<N;++i ) {
    cin >> h[i];
    dp[i] = 100000 * 10001;
  }
  dp[0] = 0;
  for (int i=0;i<N-1;++i){
    for (int j=1;j<K+1; ++j ) {
      dp[i+j] = min( dp[i+j], dp[i] + abs(h[i+j]-h[i]));
    }
  }
  cout << dp[N-1] << endl;
}
