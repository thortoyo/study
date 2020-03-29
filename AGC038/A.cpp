#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  REP(y,H) {
    REP(x,W) {
      string c = ( ((x >= A) && (y < B)) || ((x < A) && (y >= B)) ) ? "1" : "0";
      cout << c;
    }
    cout << endl;
  }
}

