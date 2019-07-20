#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector< pair< int64_t, int64_t > > xy(N);
  vector< pair< int64_t, int64_t > > yx(N);
  for (int i=0;i<N; ++i) {
    int64_t xin, yin;
    cin >> xin >> yin;
    xy[i]  = make_pair( xin, yin );
  }

  sort( xy.begin(), xy.end() );

  map< pair<int64_t,int64_t> , int > m;
  
  for (int i=0; i<N-1; ++i ) {
    for (int j=i+1; j<N; ++j ) {
      int64_t xdif = xy[j].first - xy[i].first;
      int64_t ydif = xy[j].second - xy[i].second;
      if ( m.find( make_pair( xdif,ydif) ) != m.end() ) {
        m.at(make_pair( xdif,ydif)) += 1;
      } else {
        m.insert(make_pair(make_pair( xdif,ydif),1));
      }
//        cout << xdif << " " << ydif << " " << m.at(make_pair( xdif,ydif)) << endl;
    }
  }

  int cmax = 0;
  for ( auto it=m.begin(); it != m.end(); ++it ) {
    cmax = max( cmax, it->second );
//    cout << "#cmax " << cmax << endl;
  }
  
  cout << (N-cmax) << endl;
}

