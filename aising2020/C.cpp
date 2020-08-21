#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for(int i=1; i<=n; ++i) {
    ans = 0;
    for(int x=1; x*x<=n; ++x) {
      for(int y=1; y<=x; ++y) {
        int a = i - (x*x + y*y + x*y);
        int b = x+y;
        if ( a <= 0 ) continue;
//        cout << x << " " << y << " : " << a << " " << b << endl;
        for(int z=1; z<=y; ++z) {
          if ( a == z*z + b*z ) {
            if ( x == y && y == z ) ans++;
            else if ( x == y || y == z || x == z ) ans += 3;
            else ans += 6;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
