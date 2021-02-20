#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;
ll M;

ll num(ll n, string x) {
  ll ret = 0;
  ll base = 1;
  while(x.length() > 0) {
    if ( ret > M ) return M+1;
    if ( base > M ) return M+1;
    ret += (x[ x.length()-1 ] - '0') * base;
    x.pop_back();
    if ( (M / base < n) && (x.length() > 0) ) return M+1;
    base *= n;
//    cout << "       " << x << " " << base << " " << ret<< endl;
  }
//  cout << "num " << n << " : " << ret << endl;
  return ret;
}

ll solve() {
  string X;
  cin >> X >> M;
  int xmax = 0;
  REP(i, X.length()) {
    if ( xmax < (X[i] - '0') ) xmax = (X[i] - '0');
  }

  ll l=xmax;
  ll r=M+1;
  while ( l +1 < r ) {
    ll m = (l+r) / 2;
    if ( M >= num(m, X) ) {
      l = m;
    } else {
      r = m;
    }
  }
  return l-xmax;
}

int main(){
  cout << solve() << endl;
}
