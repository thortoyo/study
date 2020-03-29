#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C ;
  vector< int > p(A), q(B), r(C);
  REP(i,A) cin >> p[i];
  REP(i,B) cin >> q[i];
  REP(i,C) cin >> r[i];

  sort( p.begin(), p.end(), greater<int>() );
  sort( q.begin(), q.end(), greater<int>() );
  sort( r.begin(), r.end(), greater<int>() );

  vector<int> t;
  REP(i,X) t.emplace_back( p[i] );
  REP(i,Y) t.emplace_back( q[i] );
  REP(i,min(C,(X+Y))) t.emplace_back( r[i] );

  sort( t.begin(), t.end(), greater<int>() );
  ll ans = 0;
  REP(i,X+Y) ans += t[i];
  
  cout << ans << endl;
}

  
