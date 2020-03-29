#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N,X,Y;
  cin >> N >> X >> Y;
  vector< vector<int> > G(N);
  X--; Y--;
  REP(i,N) {
    if (i != 0 ) G[i].push_back(i-1);
    if (i != N-1 ) G[i].push_back(i+1);
  }
  G[X].push_back(Y);
//  REP(i,N) {cout << i << " : ";
//    for ( auto a : G[i] ) cout << a << " ";
//    cout << endl;
//  }
  
  vector<int> d(N,0);
  
  REP(i,N) {
    queue<int> q;
    vector<int> D(N,-1);
    q.push(i);
    D[i] = 0;
    while( !q.empty() ) {
      int v = q.front();
      q.pop();
      for( auto nv : G[v] ) {
        if (D[nv] != -1) continue;
        D[nv] = D[v] + 1;
        if ( nv > i ) d[D[nv]] += 1;
        q.push(nv);
      }
    }
  }
  for( int i=1;i<N;i++) {
    cout << d[i] << endl;
  }
}

  
