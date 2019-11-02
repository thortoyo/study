#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

ll ans[301][301];
ll dp[301][301];

int main() {
  int N, M;
  ll L;
  cin >> N >> M >> L;
  vector< vector< pair<int,int> > > to(N);

  REP(i, N) 
    REP(j, N)
      dp[i][j] = (i==j) ? 0 : INF;
  
  REP(i,M)  {
    int ai,bi;
    ll ci;
    cin >> ai >> bi >> ci;
    if ( ci > L ) continue;
    ai--; bi--;
    to[ai].emplace_back(bi, ci);
    to[bi].emplace_back(ai, ci);
    dp[ai][bi] = ci;
    dp[bi][ai] = ci;
  }
  // ワーシャルフロイド
  REP(k, N)
    REP(i, N)
      REP(j, N)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  REP(i, N) 
    REP(j, N)
      dp[i][j] = (dp[i][j]<=L) ? 1 : INF;

  REP(k, N)
    REP(i, N)
      REP(j, N)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  int Q;
  cin >> Q;
  REP(i, Q) {
    int s,e;
    cin >> s >> e;
    s--; e--;
    ll res = dp[s][e];
    if ( res == INF ) res = 0;
    cout << res-1 << endl;
  }

}
