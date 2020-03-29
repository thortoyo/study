#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector< vector< pair<int,int> > > to(100005);
vector< int> col(100005, 0);
vector< int> par(100005, 0);


int main() {
  int N;
  cin >> N;
  int pre = 0;
  int K = 1;
  int mia = N;
  REP(i,N-1) {
    int a,b;
    cin >> a >> b;
    to[a].emplace_back(b,i);
    to[b].emplace_back(a,i);
    mia = min( mia, a );
  }
  queue<int> q;
  q.push(mia);
  while( !q.empty()){
    auto v = q.front(); q.pop();
    int c = 1;
    for( auto nv: to[v] ) {
      int nn = nv.first;
      int i = nv.second;
      if ( col[i] != 0 ) continue;
      if ( c == par[v] ) c++;
      col[i] = c;
      par[nn] = c;
      K = max(K,c);
      c++;
      q.push(nn);
    }
  }
  cout << K << endl;
  REP(i,N-1) {
    cout << col[i] << endl;
  }
}
