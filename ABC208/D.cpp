#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll f[401][401];

ll solve() {
  int N, M;
  cin >> N >> M;
  ll INF = 1LL << 62;
  REP(i,M) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    f[a][b] = c;
  }
  REP(i,N) f[i][i] = 0;
  ll ans = 0;
  REP(k,N) REP(i,N) REP(j,N) {
    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
    if (f[i][j] != INF) ans += f[i][j];
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
