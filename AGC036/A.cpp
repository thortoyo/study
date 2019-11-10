#include <bits/stdc++.h>
using namespace std;


int main() {
  uint64_t x1,x2,y1,y2;
  uint64_t S;
  cin >> S;
  double rs = sqrt((double)S);
  uint64_t irs = rs;
  int64_t sub1;
  x1 = irs;
  y2 = irs;
  sub1 = x1 * y2 - S;
  if ( sub1 < 0 ) {
    y2 = irs+1;
    sub1 = x1 * y2 - S;
  }
  if ( sub1 < 0 ) {
    x1 = irs + 1;
    sub1 = x1 * y2 - S;
  }
  if ( sub1 == 0 ){
    x2 = 0;
  } else {
    x2 = 1;
  }
  y1 = sub1;

  cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

