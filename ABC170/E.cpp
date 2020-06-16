#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N,Q;
  cin >> N >> Q;
  vector< multiset<ll, greater<ll> > > y(200005);
  multiset<ll> mm;
  vector< ll > es(N+1), ey(N+1);
  REP(i,N) {
    ll a,b;
    cin >> a >> b;
    es[i+1] = a;
    ey[i+1] = b;
    y[b].insert(a);
  }
  // Še—c’t‰€‚ÌÅ‘å’l‚ðmultiset‚ÉŠi”[
  REP(i,200005) {
    if ( !y[i].empty() ) {
      mm.insert(*(y[i].begin()));
    }
  }

  
  REP(i,Q) {
    int c,d;
    cin >> c >> d;
    mm.erase( mm.find(*(y[ey[c]].begin())) );
    if ( !y[d].empty() )  mm.erase( mm.find(*(y[d].begin())) );
//    cout << "1 : ";
//    for ( auto m : mm ) cout << m << " "; cout << endl;
    y[ey[c]].erase( y[ey[c]].find(es[c]) );
    y[d].insert( es[c] );
    if ( !y[ ey[c] ].empty() )
      mm.insert( *(y[ ey[c] ].begin()) );
    mm.insert( *(y[ d ].begin()) );
    ey[c] = d;
//    cout << "2 : ";
//    for ( auto m : mm ) cout << m << " "; cout << endl;
    
    // Še—c’t‰€‚ÌÅ‘å’l’B‚Ì‚¤‚¿‚ÌÅ¬’l
    cout << *(mm.begin()) << endl;
  }
}

  
