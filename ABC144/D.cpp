#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const double PI = 3.141592653585;

double r0, total;
double a,b, x;

double GetCapa( double r ) {
  if ( r0 > r ) {
    return total - (a * a * tan(r) * a / 2);
  } else {
    return b * b * tan(PI/2-r) * a / 2;
  }
}

int main() {
  cin >> a >> b >> x;

  r0 = atan( b/a );
  total = a * a * b;

  double r_lit = 0;
  double r_big = PI/2;
  double rt;

  while ( 1 ) {
    rt = (r_big - r_lit) / 2 + r_lit; 
//    cout << " " << rt << " " << r_big << " " << r_lit <<endl;
    double capa = GetCapa( rt );
//    cout << r0 << " : " << rt << " : " << capa << " " << fabs(capa - x) << endl;
    if ( fabs(capa - x) <= 0.0000001 ) break;
    if (capa > x ) {
      r_lit = rt;
    } else {
      r_big = rt;
    }
  }

  cout << fixed << setprecision(10) << rt/PI*2*90 << endl;
}
