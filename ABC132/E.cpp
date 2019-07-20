#include <bits/stdc++.h>
using namespace std;
 
using Graph = vector< vector< int > > ;
 
const int64_t smax = 1001001 * 3; 
vector<int64_t> seen(100002*3, smax);

 
int main() {
  int N,M,S,T;
  cin >> N >> M;
 
  Graph G((N+1)*3);
  for (int i=0;i<M;++i ) {
    int a,b;
    cin >> a >> b;
//    --a; --b;
    G[3*a].push_back(3*b+1);
    G[3*a+1].push_back(3*b+2);
    G[3*a+2].push_back(3*b);
  }
  cin >> S >> T;
//  --S; --T;
  queue<int> q;
  q.push(S*3);
  seen[S*3] = 0;
  while( !q.empty() ) {
    int v = q.front();
    q.pop();
    for( auto next_v : G[v] ) {
      if (seen[next_v] != smax) continue;
      seen[next_v] = seen[v] + 1;
      q.push(next_v);
    }
  }
  if (seen[T*3] != smax) cout << seen[T*3]/3 << endl;
  else cout << "-1" << endl;
}
