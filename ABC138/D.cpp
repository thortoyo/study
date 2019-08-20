#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > G(200005);
vector< int64_t > cnt(200005, 0);
vector< bool > visit(200005, false);

void BFS( int v, int64_t pval ) {
  cnt[v] += pval;
  visit[v] = true;
  for( auto a : G[v] ) {
    if ( visit[a] ) continue;
    BFS( a, cnt[v] );
  }
}

int main() {
  int N,Q;
  cin >> N >> Q;

  for( int i=0; i<N-1; ++i) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for( int i=0; i<Q; ++i) {
    int64_t p,x;
    cin >> p >> x;
    cnt[--p] += x;
  }

  BFS(0,0);

  for( int i=0;i<N;i++ ) {
    cout << cnt[i] << " ";
  }
  
  cout << endl;

}
