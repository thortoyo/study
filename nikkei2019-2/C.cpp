#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector< vector<int> > to(100005);
int visit[100005];

void DFS( int v ) {
  for ( auto nv: to[v] ) {
    if (visit[nv] == 1) continue;
    visit[nv] = 1;
    DFS(nv);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  vector< pair<int,int> >  AI(N), BI(N);
  REP(i,N) cin >> A[i];
  REP(i,N) cin >> B[i];
//  REP(i,N) BA[i] = make_pair( B[i], A[i] );

//  sort(BA.begin(), BA.end());
//  sort(A.begin(), A.end());
//  sort(B.begin(), B.end());

  REP(i,N) AI[i] = make_pair( A[i], i );
  sort(AI.begin(), AI.end());
  REP(i,N) BI[i] = make_pair( B[i], i );
  sort(BI.begin(), BI.end());

  // N-2âÒÇÃSwapÇ≈AÇÉ\Å[ÉgÇ≈Ç´ÇÈÇ©îªíË
  bool sortok = false;
  REP(i,N)
    to[AI[i].second].push_back( BI[i].second );
  DFS(0);
  REP(i,N)
    if ( visit[i] == 0) sortok = true;
//  REP(i,N) {
//    cout << i << " : v " << visit[i] << " : ";
//    for ( auto x : to[i] ) 
//      cout << x << " ";
//    cout << endl;
//  }
//  cout << sortok << endl;
  
  bool ok = true;
  if (sortok) {
    REP(i,N) {
      if ( AI[i].first > BI[i].first ) ok = false;
    }
  } else {
    REP(i,N) {
      if ( AI[i].first > BI[i].first ) ok = false;
    }
    if (ok) {
      ok = false;
      REP(i,N-1) {
        if ( (AI[i].first <= BI[i].first) && (AI[i+1].first <= BI[i].first) ) ok = true;
      }
    }
  }
  if ( ok ) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
