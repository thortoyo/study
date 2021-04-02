#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// ‰ñ“]s—ñ
// | cos -sim |
// | sin  cos |

void solve() {
  int N;
  cin >> N;
  double x0,y0,xh,yh, x, y, offx, offy;
  cin >> x0 >> y0;
  cin >> xh >> yh;
  offx = (x0 + xh) / 2.0;
  offy = (y0 + yh) / 2.0;
  double rad = 2.0 * M_PI / (double)N;
//  printf("%.7f %.7f\n",offx,offy);
  x = cos( rad ) * (x0-offx) - sin( rad ) * (y0-offy) + offx;
  y = sin( rad ) * (x0-offx) + cos( rad ) * (y0-offy) + offy;
  printf("%.7f %.7f\n",x,y);
  return;
}

int main(){
  solve();
}
