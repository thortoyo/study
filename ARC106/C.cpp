#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N,M;
  cin >> N >> M;
  if (M < 0) cout << "-1" << endl;
  else if ( N==1 && M==0) {
    cout << "1 2" << endl;
  } else if ( N-M <= 1 ) {
    cout << "-1" << endl;
  } else if ( M==0 ) {
    REP(i, N) cout << (2*i+1) << " " << (i*2+2) << endl;
  } else {
    cout << "1 " << (4+2*M) << endl;
    cout << "2 3" << endl;
    REP(i, M) {
      cout << (4+i*2) << " " << (4+i*2+1) << endl;
    }
    REP(i, (N-M-2) ) {
      cout << (4+2*M+i*2+2) << " " << (4+2*M+i*2+3) << endl;
    }
  }
}
