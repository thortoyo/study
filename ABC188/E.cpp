#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

const ll INF = 1123456789;

int solve() {
  int N,M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> t(N,0);
  vector<int> m(N,INF);
  vector< vector< int > > G(N);
  REP(i,N) cin >> A[i];
  REP(i,M) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    G[x].emplace_back( y );
    t[x] = 1;
    t[y] = 0;
  }

  int ans = -INF;
  REP(i,N) {
    if ( t[i] == 1 ) {
      // ダイクストラ
      priority_queue< pair<int, int> > q;
      q.emplace( INF, i );

      while( !q.empty() ) {
        auto v = q.top(); q.pop();
        int vv = v.second;
        m[vv] = min(v.first, A[vv]);
//        cout << vv << " : " << v.first << " " << m[vv] << endl;
        for ( auto nv : G[vv] ) {
          if ( m[nv] <= m[vv] ) continue;
          ans = max( ans, A[nv] - m[vv] );
          q.emplace(m[vv], nv);
        }
      }
    }
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
