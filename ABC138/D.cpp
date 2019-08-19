#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > G(200005);
vector< int64_t > cnt(200005, 0);
vector< int64_t > px(200005, 0);

void BFS( int v, int64_t pval ) {
  cnt[v] = px[v] + pval;
  for( auto a : G[v] ) {
    BFS( a, cnt[v] );
  }
}

int main() {
  int N,Q;
  cin >> N >> Q;

  for( int i=0; i<N-1; ++i) {
    int a,b;
    cin >> a >> b;
    G[--a].push_back(--b);
  }

  for( int i=0; i<Q; ++i) {
    int64_t p,x;
    cin >> p >> x;
    px[--p] += x;
  }

  BFS(0,0);

  for( int i=0;i<N;i++ ) {
    cout << cnt[i] << " ";
  }
  
  cout << endl;

}
