#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll cost[(2 << 12) + 1 ];
ll dp[(2 << 12) + 1 ];

int main() {
  int N,M;
  cin >> N >> M;
  REP(i, 2<<(N-1)) dp[i] = 10000000000;
  REP(i, 2<<(N-1)) cost[i] = 10000000000;
  REP(i,M) {
    ll a,b;
    cin >> a >> b;
    int cmask = 0;
    REP(j,b) {
      int c;
      cin >> c;
      cmask |= (1 << (c-1));
    }
    cost[cmask] = min( cost[cmask], a );
  }
//  REP(i, 2<<(N-1)) cout << i << " : cost " << cost[i] << endl;
  dp[0] = 0;
  REP(i, 2<<(N-1)) REP(j, 2<<(N-1)) {
    dp[i|j] = min( dp[i|j], dp[i] + cost[j]);
//    cout << i << " " << j << " : " << dp[i|j] << endl;
  }

  ll ans = (dp[(2<<(N-1))-1] == 10000000000) ? -1 : dp[(2<<(N-1))-1];
  cout << ans << endl;
}
