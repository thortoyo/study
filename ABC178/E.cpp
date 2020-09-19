#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> x(N),y(N);
  REP(i,N) {
    cin >> x[i] >> y[i];
  }
  ll xymax[4] = {-2000000005,-2000000005,-2000000005,-2000000005};
  ll xymin[4] = {2000000005,2000000005,2000000005,2000000005};
  REP(i,N) {
    xymax[0] = max( xymax[0], x[i] + y[i] );
    xymin[0] = min( xymin[0], x[i] + y[i] );
    xymax[1] = max( xymax[1], x[i] - y[i] );
    xymin[1] = min( xymin[1], x[i] - y[i] );
    xymax[2] = max( xymax[2], - x[i] + y[i] );
    xymin[2] = min( xymin[2], - x[i] + y[i] );
    xymax[3] = max( xymax[3], - x[i] - y[i] );
    xymin[3] = min( xymin[3], - x[i] - y[i] );
  }
  ll ans = 0;
  REP(i,4) {
    ans = max( ans, xymax[i] - xymin[i] );
  }
  cout << ans << endl;

}
