#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A(N),B(N), C(N);
  vector< pair<int,int> > BA(N), AI(N);
  REP(i,N) cin >> A[i];
  REP(i,N) cin >> B[i];
  REP(i,N) BA[i] = make_pair( B[i], A[i] );

  sort(BA.begin(), BA.end());
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  REP(i,N) AI[i] = make_pair( BA[i].second, i );
  sort(AI.begin(), AI.end());

  // N-2‰ñ‚ÌSwap‚ÅA‚ðƒ\[ƒg‚Å‚«‚é‚©”»’è
  bool sortok = false;
  REP(i,N) {
    if (BA[i].second == A[i] ) {sortok = true;break;}
    if (AI[AI[i].second].first == BA[i].second ) {sortok = true; break;}
  }
  if ( N==2 ) {
    sortok = false;
    REP(i,N) {
      if (BA[i].second == A[i] ) {sortok = true;break;}
    }
  }

  bool ok = true;
  if (sortok) {
    REP(i,N) {
      if ( A[i] > B[i] ) ok = false;
    }
  } else {
    REP(i,N) {
      if ( A[i] > B[i] ) ok = false;
    }
    if (ok) {
      ok = false;
      REP(i,N-1) {
        if ( (A[i] <= B[i]) && (A[i+1] <= B[i]) ) ok = true;
      }
    }
  }
  if ( ok ) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
