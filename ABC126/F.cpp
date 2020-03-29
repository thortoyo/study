#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int M,K;
  cin >> M >> K;
  int m2 = 1 << M;
  
  if ( M == 0 ) {
    if ( K == 0 ) {
      cout << "0 0" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  } else if ( M == 1 ) {
    if ( K == 0 ) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }
  if ( K >= m2 ) {
    cout << "-1" << endl;
    return 0;
  }
  REP(i, m2) {
    if ( i != K ) {
      cout << i << " ";
    }
  }
  cout << K << " ";
  for (int i=m2-1; i>=0; --i ){
    if ( i != K ) {
      cout << i << " ";
    }
  }
  cout << K << endl;
}
