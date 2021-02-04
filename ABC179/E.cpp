#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main(){
  ll N,X,M;
  cin >> N >> X >> M;
  map<int, int> m;
  int a = X;
  m[a] = 1;
  ll ans = 0;
  vector<int> al(M+1,0);
  al.push_back(a);
  int lp = 0;
      int ln = 0;
  REP(i,M) {
    a = X * X % M;
    al.push_back(a);
    if ( m[a] != 0 ) {
      lp = m[a];
      ln = i+2 - m[a];
      break;
    }
  }
  if ( lp == 0 ) {
    ans = al[N];
  } else {
    ll xx = (X-lp-1) % ln;
    ans = al[lp-1 + xx];
  }
  cout << ans << endl;

}
