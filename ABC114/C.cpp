#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll N;
ll a[3];

ll dfs( ll num ) {
  if (num > N) return 0;
  ll v = num;
  vector<bool> f(10,false);
  REP(i, 10) {
    f[ v%10 ] = true;
    v /= 10;
  }
  ll ret = 0;
  if ( f[3] && f[5] && f[7] ) ret = 1;
  REP(j,3)
    ret += dfs( num *10 + a[j] );
  return ret;
}


int main() {
  cin >> N;
  a[0] = 3;
  a[1] = 5;
  a[2] = 7;
  cout << dfs(0) << endl;
}
