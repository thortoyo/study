#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll X;
  cin >> X;
  ll a, b;
  ll i = 2;
  int f = 0;
  for( a=-1000; a<1000; a++ ) {
    for( b=-1000; b<1000; b++ ) {
      if ( a*a*a*a*a - b*b*b*b*b == X ) {
        cout << a << " " << b << endl;
        f = 1;
        break;
      }
    }
    if ( f == 1 ) break;
  }

//  cout << ans << endl;
}
