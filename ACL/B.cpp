#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N,Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  REP(i,N) {
    ll a;
    cin >> a;
    fw.add(i,a);
  }
  REP(i,Q) {
    int t,a,b;
    cin >> t >> a >> b;
    if (t==0) {
      fw.add(a,b);
    } else {
      cout << fw.sum(a,b) << endl;
    }
  }
}
