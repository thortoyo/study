#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int vis[212345];
vector< vector<int> > to(212345);

void DFS(int v) {
  vis[v] = 1;
  cout << (v+1) << " ";
  for ( auto nv: to[v] ) {
    if ( vis[nv] == 1 ) continue;
    DFS(nv);
    cout << (v+1) << " ";
  }
}

void solve() {
  int N;
  cin >> N;
  REP(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  REP(j,N) vis[j] = 0;
  REP(j,N) sort(to[j].begin(), to[j].end());
  DFS(0);
  return;
}

int main(){
  solve();
  cout << endl;
}
