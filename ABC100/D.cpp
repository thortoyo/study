#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  vector<ll> x(N), y(N), z(N);
  REP(i,N)  {
    cin >> x[i] >> y[i] >> z[i];
  }
  ll ans = 0;
  REP(a,8) {
    vector<ll> K(N);
    REP(i,N) {
      ll t = (a&1) ? -x[i] : x[i];
      t += (a&2) ? -y[i] : y[i];
      t += (a&4) ? -z[i] : z[i];
      K[i] = t;
    }
    sort(K.begin(),K.end(),greater<ll>());
    ll tt = 0;
    REP(i,M) tt += K[i];
    ans = max( ans, tt );
  }
  cout << ans << endl;

}
  
