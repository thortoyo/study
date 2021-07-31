#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


void solve() {
  int Q;
  cin >> Q;
  priority_queue <ll, vector<ll>, greater<ll> > B;
  ll of = 0;
  REP(i,Q) {
    ll p,x;
    cin >> p;
    if (p != 3) cin >> x;
    if (p==1) {
      B.push( x-of );
    } else if (p==2) {
      of += x;
    } else {
      cout << (B.top()+of) << endl;
      B.pop();
    }
  }
  return;
}

int main(){
  solve();
}
