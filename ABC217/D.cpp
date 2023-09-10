#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


void solve() {
  int L,Q;
  cin >> L >> Q;
  vector<int> c(Q), x(Q);
  REP(i,Q)  cin >> c[i] >> x[i];
  set<int> KI;
  KI.insert(0);
  KI.insert(L);

  REP(i,Q) {
    if ( c[i] == 1 ) {
      KI.insert(x[i]);
    } else {
      auto xr = KI.upper_bound(x[i]);
      auto xl = prev(xr);
      cout << (*xr-*xl) << endl;
//      cout << *xl << " " << *xr << endl;
    }
//    auto j = KI.begin();
//    cout << "KI: ";
//    while( j != KI.end() )
//      cout << *j++ << " ";
//    cout << endl;
  }

  return;
}

int main(){
  solve();
}


