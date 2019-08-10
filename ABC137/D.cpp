#include <bits/stdc++.h>
using namespace std;

multimap<int,int> AB;
multiset<int> B;

int main() {
  int N,M;
  cin >> N >> M;

  for( int i=0; i<N; ++i) {
    int a,b;
    cin >> a >> b;
    AB.emplace(a,b);
  }

//  for( auto a: AB ) cout << a.first << ":" << a.second << endl;
  
  int64_t ans = 0;
  // M“ú–Ú‚©‚ç’T‚·
  decltype(AB)::iterator nit = AB.begin();
  for( int64_t t=M-1; t>=0; --t) {
//    cout << "--- " << t << " ---" << endl;
    // Œ»Ý‚Ì“ú‚ÅŽó‚¯‚ê‚é‚à‚Ì(t+A<=M)‚Ì’†‚ÅABÅ‘å‚Ì‚à‚Ì‚ð‘I‚Ô
    auto at = AB.upper_bound( M-t );
//    cout << at->first << ":" << at->second << endl;
    
    int64_t bmax=0;
    while( distance( nit, at ) > 0 ) {
      B.insert( nit->second );
      nit++;
    }
    if ( !B.empty() ) {
      auto bit = B.end();
      bit--;
//      cout << *bit << endl;
      ans += *bit;
      B.erase(bit);
    }
  }

  cout << ans<< endl;

}
