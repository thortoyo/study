#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  vector< pair<int, int> > ans;
  int m = 0;
  int amax = -10000000, amin = 10000000;
  int amaxn, aminn;
  bool allp = true, allm = true;
  REP(i,N) {
    cin >> A[i];
    if ( amax < A[i] ) {
      amax = A[i];
      amaxn = i;
    }
    if ( amin > A[i] ) {
      amin = A[i];
      aminn = i;
    }
    if ( A[i] >= 1 ) allm = false;
    if ( A[i] <= -1 ) allp = false;
  }
  if ( !allp && !allm ) {
    m = N;
    if ( abs(amax) > abs(amin) ) {
      REP(i,N) ans.push_back( { amaxn+1, i+1 } );
    } else {
      REP(i,N) ans.push_back( { aminn+1, i+1 } );
    }
  }
  m += N-1;
  if ( abs(amax) > abs(amin) ) {
    REP(i,N-1) ans.push_back( {i+1, i+2} );
  } else {
    for(int i=N; i>=2; i--) ans.push_back( {i, i-1} );
  }
  cout << m << endl;
  for ( auto a : ans )
    cout << a.first << " " << a.second << endl;
}

