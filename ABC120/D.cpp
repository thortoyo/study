#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


struct UnionFind {
  vector<int> par;
  vector<ll> nnum;
  UnionFind( int n ) {
    init(n);
  }
  void init( int n ) {
    par.resize(n);
    nnum.resize(n);
    for ( int i=0;i<n;++i ) par[i] = i;
    for ( int i=0;i<n;++i ) nnum[i] = 1;
  }
  int root( int a ) {
    if ( par[a] == a ) return a;
    return par[a] = root(par[a]);
  }
  ll merge( int a, int b ) {
    int ra = root(a);
    int rb = root(b);
    if ( ra == rb ) return 0;
    ll ret = nnum[ra] * nnum[rb];
    if ( nnum[ra] > nnum[rb] ) swap( ra, rb );
    par[ra] = rb;
    nnum[rb] += nnum[ra];
    return ret;
  }
};

int main() {
  int N,M;
  cin >> N >> M;
  UnionFind uf(N);
  vector<ll> ans(M+1);
  vector<int> A(M), B(M);
  REP(i,M) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }

  ans[M] = (ll)N * ((ll)N-1LL) / 2LL;
  for ( int i=M-1; i>0; --i ) {
    ans[i] = ans[i+1] - uf.merge( A[i], B[i] );
//    cout << i << " " << ans[i] << endl;
  }
  REP(i,M) {
    cout << ans[i+1] << endl;
  }
}

