#include <bits/stdc++.h>
using namespace std;

using Graph = vector< vector< pair<int.int> > > ;

vector<int> seen;

bool dfs( const Graph &G, int v, int col) {
  seen[v] = col;

  for( auto next_v : G[v] ) {
    if (col==1) {
      if (seen[next_v.first] == 1) return false;
      if (seen[next_v.first] == 0) continue;
      if (!dfs(G, next_v , 0)) return false;
    } else {
      if (seen[next_v] == 0) return false;
      if (seen[next_v] == 1) continue;
      if (!dfs(G, next_v, 1)) return false;
    }
  }
  return true;
}


int main() {
  int N;
  cin >> N;

  Graph G(N);
  for (int i=0;i<N-1;++i ) {
    int u,v,w;
    cin >> u >> v >> w;
    G[u].push_back( make_pair(v,w) );
    G[v].push_back( make_pair(u,w) );
  }
//  for( int i=0;i<N;++i) {
//    cout << i << " :";
//    for( auto g0 : G[i] ) {
//      cout << " " << g0;
//    }
//    cout << endl;
//  }

  seen.assign(N,-1);
  
  dfs(G,0,0);

  for ( int i=0;i<N;i++) {
    cout << seen[i] << endl;
  }

}
