#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int divisor[105];

void mk_divisor( int num ) {
  for( int i=2; i*i<=num; ++i ) {
    while ( num % i == 0 ) {
      num /= i;
      divisor[i]++;
    }
  }
  if ( num != 1 ) divisor[num]++;
  return;
}

int main() {
  ll N;
  cin >> N;
  REP(i,N+1) {
    mk_divisor( i );
//    REP(j,N+1) cout << j << ":" << divisor[j] << ",  ";
//    cout << endl;
  }
//  REP(j,N+1) cout << j << ":" << divisor[j] << endl;
  int ans = 0;
  int o75, o25, o15, o5, o3;
  o75 = o25 = o15 = o5 = o3 = 0;
  REP(i,N+1) {
    if (divisor[i] >= 74) o75++;
    if (divisor[i] >= 24) o25++;
    if (divisor[i] >= 14) o15++;
    if (divisor[i] >= 4) o5++;
    if (divisor[i] >= 2) o3++;
  }
  // 75
  ans += o75;
  // 75 = 3 * 25
  if ( o3 > 1 )
    ans += o25 * (o3 - 1);
  // 75 = 15 * 5
  if ( o5 > 1 )
    ans += o15 * (o5 - 1);
  // 75 = 3 * 5 * 5
  if ( (o5 > 1) && (o3 > 2) )
    ans += o5 * (o5-1) / 2 * (o3 - 2);
  cout << ans << endl;
}
