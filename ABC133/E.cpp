#include <bits/stdc++.h>
using namespace std;

using Graph = vector< vector<int> > ;
const int64_t MOD = 1000000007;

int main() {
  int N,K;
  cin >> N >> K;

  Graph G(N+1);
  vector<int> seen(N+1,-1);
  for (int i=0;i<N-1;++i ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
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

  int64_t ans = K;
  int64_t child = K-1;
  
  queue<int> q;
  q.push(0);
  seen[0] = K-1;
  while( !q.empty() ) {
    int v = q.front(); q.pop();
    child = seen[v];
//    cout << v << ":";
    for ( auto a: G[v] ) {
//      cout << a << "-";
      if ( seen[a] != -1) continue;
//      cout << a << " " << child << ", ";
      q.push(a);
      ans = (ans * child) % MOD;
      child--;
      seen[a] = K-2;
    }
//    cout << endl;
  }
  cout << ans << endl;
}
