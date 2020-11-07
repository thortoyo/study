#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

using mint = modint998244353;

ll A[50][50];

int main() {
  int N,K;
  cin >> N >> K;
  REP(y,N)  REP(x,N) cin >> A[y][x];
  mint ans=1;

  dsu d(N);
  REP(y,N-1) {
    for( int y1=y+1; y1<N; y1++ ) {
      int ok = 1;
      REP(x,N) {
        if (A[y][x] + A[y1][x] > K ) { ok = 0; break; }
      }
      if (ok==1) d.merge(y,y1);
    }
  }
  REP(i,N) {
    if ( i == d.leader(i) ) {
      REP(j, d.size(i))
      ans *= (j+1);
    }
  }

  dsu d2(N);
  REP(x,N-1) {
    for( int x1=x+1; x1<N; x1++ ) {
      int ok = 1;
      REP(y,N) {
        if (A[y][x] + A[y][x1] > K ) { ok = 0; break; }
      }
      if (ok==1) d2.merge(x,x1);
    }
  }
  REP(i,N) {
    if ( i == d2.leader(i) ) {
      REP(j, d2.size(i))
      ans *= (j+1);
    }
  }
  cout << ans.val() << endl;
}
