#include <bits/stdc++.h>
using namespace std;

using Graph = vector< vector<int> > ;

vector<bool> seen;

void dfs( const Graph &G, int v) {
  seen[v] = true;
  cout << v << " ";

  for( auto next_v : G[v] ) {
    if (seen[next_v] == true) continue;
    dfs(G, next_v);
    cout << endl;
  }
}


int main() {
  int N,M,s,t;
  cin >> N >> M >> s >> t;

  Graph G(N);
  for (int i=0;i<M;++i ) {
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
  }
//  for( int i=0;i<N;++i) {
//    cout << i << " :";
//    for( auto g0 : G[i] ) {
//      cout << " " << g0;
//    }
//    cout << endl;
//  }

  
  seen.assign(N,false);
  dfs(G,s);
  if (seen[t] == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
