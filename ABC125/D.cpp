#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// dp[i][0]: Ai�ɑ΂��đ��삵�Ȃ��ꍇ�́AAi�܂ł̍��v��
// dp[i][1]: Ai�ɑ΂��đ��삵���ꍇ�́AAi�܂ł̍��v��
ll dp[100005][2];

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i,N) {
    cin >> A[i];
  }
  dp[0][0] = A[0];
  dp[0][1] = -A[0];

  REP(i,N-1) {
    dp[i+1][0] = max( dp[i][0] + A[i+1], dp[i][1] - A[i+1] );
    dp[i+1][1] = max( dp[i][0] - A[i+1], dp[i][1] + A[i+1] );
  }
  cout << dp[N-1][0] << endl;

//  REP(i,N) cout << dp[i][0] << " " << dp[i][1] << endl;
  
}

