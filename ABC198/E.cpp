#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int N;
int C[100005];
int col[10005] ;
bool used[100005];
vector< vector<int> > to(100005);
vector< int > ans;

void DFS(int v){
  if ( col[C[v]] == 0 ) ans.push_back(v+1);
  col[C[v]]++;
  for( auto nv : to[v] ) {
    if ( used[nv] ) continue;
    used[nv] = true;
    DFS(nv);
    used[nv] = false;
  }
  col[C[v]]--;
  return;
}

void solve() {
  cin >> N;
  REP(i,N) cin >> C[i];
  REP(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  used[0] = true;
  DFS(0);
  sort(ans.begin(), ans.end());
  for ( auto v : ans ) {
    cout << v << endl;
  }
  return;
}

int main(){
  solve();
}
