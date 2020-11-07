#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N,Q;
  cin >> N >> Q;
  dsu d(N);

  REP(i,Q) {
    int t,a,b;
    cin >> t >> a >> b;
    if (t==0) {
      d.merge(a,b);
    } else {
      if ( d.same(a,b) ) cout << "1" << endl;
      else cout << "0" << endl;
    }
  }
}
