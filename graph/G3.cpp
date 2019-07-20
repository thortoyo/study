#include <bits/stdc++.h>
using namespace std;

using Graph = vector< vector<int> > ;

vector<int> seen;

bool dfs( const Graph &G, int v, int col) {
  seen[v] = col;
  cout << v << "(" << col << ") ";

  for( auto next_v : G[v] ) {
    if (col==1) {
      if (seen[next_v] == 1) return false;
      if (seen[next_v] == 0) continue;
      if (!dfs(G, next_v, 0)) return false;
    } else {
      if (seen[next_v] == 0) return false;
      if (seen[next_v] == 1) continue;
      if (!dfs(G, next_v, 1)) return false;
    }
    cout << endl;
  }
  return true;
}


int main() {
  int N,M;
  cin >> N >> M;

  Graph G(N);
  for (int i=0;i<M;++i ) {
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
//  for( int i=0;i<N;++i) {
//    cout << i << " :";
//    for( auto g0 : G[i] ) {
//      cout << " " << g0;
//    }
//    cout << endl;
//  }

  seen.assign(N,-1);
  
  if (dfs(G,0,0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
