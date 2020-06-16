#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector< vector<int> > to(100010);
int dist[100010];
int pre[100010];
const int INF = 20000000;


int main(){
  int N,M;
  cin >> N >> M;
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }

  REP(i,N) dist[i] = INF;
  queue< int > q;
  q.push( 0 );
  dist[0] = 0;
  while( !q.empty()){
    auto v = q.front();  q.pop();
    for ( auto nv: to[v] ) {
      if (dist[nv] <= dist[v]+1 ) continue;
      dist[nv] = dist[v]+1;
      pre[nv] = v;
      q.push( nv );
    }
  }

  int ok = 1;
  REP(i,N) if (dist[i] == INF) ok = 0;
//  REP(i,N) cout << dist[i] << endl;
  if (ok==0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for(int i=1; i<N; i++ ) cout << (pre[i]+1) << endl;
  }
}
