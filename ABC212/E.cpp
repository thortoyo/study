#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

using mint = modint998244353;

// dp[i][j] : i“ú‚ÌŽž‚ÉA“sŽsj‚É‚¢‚éŒo˜H‚Ì”
mint dp[5005][5005];

ll solve() {
  int N,M,K;
  cin >> N >> M >> K;
  REP(i,5005) REP(j,5005) dp[i][j] = 0;
  vector< vector<int> > brk(N);
  REP(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    brk[u].emplace_back(v);
    brk[v].emplace_back(u);
  }
  dp[0][0] = 1;
  mint pre = 1;
  vector<mint> preb(N,0);
  for ( auto i : brk[0] ) preb[i] = 1;
  REP(i,K) {
    mint tmp = 0;
    vector<mint> tmp_preb(N,0);
    REP(j,N) {
      dp[i+1][j] = pre - preb[j] - dp[i][j];
      tmp += dp[i+1][j];
      for ( auto v : brk[j] ) tmp_preb[v] += dp[i+1][j];
    }
    pre = tmp;
    swap(preb, tmp_preb);
//    printf("pre %d\n",pre);
  }
//  REP(i,K) {
//    REP(j,N) {
//      printf(" %d", dp[i][j]);
//    }
//    printf("\n");
//  }
  return dp[K][0].val();

}

int main(){
  cout << solve() << endl;
}
