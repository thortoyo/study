#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll A, B;
  cin >> A >> B;
  ll ans = 0;
  for ( int i=62; i>=1; --i ) {
    bool evenA = true;
    bool evenB = true;
    if ( (A & (1LL<<i)) != 0 ) {
      if ( (A & ((1LL << (i+1))-1)) % 2 == 1 ) {
        evenA = false;
      }
    }
    if ( (B & (1LL<<i)) != 0 ) {
      if ( (B & ((1LL << (i+1))-1)) % 2 == 0 ) {
        evenB = false;
      }
    }
    if ( (!evenA && evenB) || (evenA && !evenB) ) {
      ans |= (1LL << i);
    }
//    cout << i << " : " << evenA << " " << evenB << " : " << ans << endl;
  }
  ll a0 = A & 1LL;
  ll b0 = B & 1LL;
  ll ba = (B - A + 1LL) / 2LL;
  if ( (a0 == 1) && (b0 == 1) ) ba++;
  if ( ba % 2 == 1 ) ans |= 1LL;
  cout << ans << endl;
}
