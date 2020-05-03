#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  long double A;
  ll N,B;
  cin >> A >> B >> N;
  long double fp, ip, x;
  x = min( B-1, N );
  fp = modf( x * A / B, &ip );
  ll ans = (ll)ip;
  cout << ans << endl;
}
