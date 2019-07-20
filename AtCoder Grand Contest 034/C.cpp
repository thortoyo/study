#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X,bin,lin,uin;
  int64_t total = 0;
  int64_t score_t = 0;
  int64_t score_a = 0;
  vector< tuple< int, int,int,int > > T;
  cin >> N >> X;
  
  for (int i=0;i<N;i++ ) {
    cin >> bin >> lin >> uin;
    score_a += lin * bin;
    T.push_back( make_tuple( (X-bin)*(uin-lin), bin, lin, uin ) );
  }
  sort(T.begin(),T.end());
  reverse(T.begin(),T.end());

  for ( auto a: T ) {
    int d,b,l,u;
    tie(d,b,l,u) = a;
    score_t += X * u;
    score_a += b * (u-l);
    if (score_t > score_a) {
      total += (score_t - score_a + 1) / u;
      break;
    } else {
      total += X;
    }
  }
  
  cout << total << endl;
}
 