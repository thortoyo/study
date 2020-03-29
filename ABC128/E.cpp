#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Q;
  cin >> N >> Q;

  vector< tuple< int, int, int > > stx(N);
  for (int i=0;i<N; ++i) {
    int sin, tin, xin;
    cin >> sin >> tin >> xin;
    stx[i] = make_tuple( xin, sin-xin, tin-xin );
  }

  sort( stx.begin(), stx.end() );

  set< pair< int,int > > D;
  vector< int > DO(Q,-1);
  
  for (int i=0; i<Q; ++i ) {
    int din;
    cin >> din;
    D.emplace( din,i );
  }
  for ( auto a: stx ) {
//      cout << "#" << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;
    auto first = D.lower_bound( make_pair( get<1>(a), 0) );
    auto last = D.upper_bound( make_pair( get<2>(a)-1, Q) );
    for ( auto it = first; it != last; ++it ) {
      DO[ it->second ] = get<0>(a);
    }
    D.erase(first,last);
  }
  for (int i=0;i<Q;++i ) {
    cout << DO[i] << endl;
  }
}

