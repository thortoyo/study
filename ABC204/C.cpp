#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int vis[2002];
int ton;
vector< vector<int> > to(2002);

void DFS(int v) {
  vis[v] = 1;
  ton++;
  for ( auto nv: to[v] ) {
    if ( vis[nv] == 1 ) continue;
    DFS(nv);
  }
}

int solve() {
  int N,M;
  cin >> N >> M;
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
  }
  ll ans = 0;
  REP(i,N){
    REP(j,N) vis[j] = 0;
    DFS(i);
    ans += ton;
    ton = 0;
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
