#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  int64_t cnt = 0;
  cin >> N;
//  N = 200000;
  vector<int> a(N+2,0), b(N+2,0);
  for( int64_t i=1; i<N+1; ++i) {
    cin >> a[i];
  }

  for(int64_t i=N; i>N/2; --i ) {
    b[i] = a[i];
    if( b[i] == 1 ) ++cnt;
  }
  for(int64_t i=N/2; i>0; --i ) {
    for(int64_t j=i*2; j<N+1; j+=i ) {
      b[i] ^= b[j];
//      cout << i << " " << j << " " << b[j] << endl;
    }
    b[i] ^= a[i];
    if( b[i] == 1 ) ++cnt;
  }
  cout << cnt << endl;
  for(int64_t i=0;i<N;++i) {
    if (b[i+1] == 1) {
      cout << (i+1) << " ";
    }
  }
  cout << endl;

}
