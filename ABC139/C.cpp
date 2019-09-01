#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  vector<int64_t> H(N);
  int cnt = 0;
  int cmax = 0;
  int ans = 0;
  for( int i=0; i<N; ++i) {
    cin >> H[i];
  }
  for( int i=0; i<N-1; ++i) {
//    cout << cnt << endl;
    if (H[i] >= H[i+1]) {
      cnt++;
    } else {
      if ( cmax < cnt ) {
        cmax = cnt;
      }
      cnt = 0;
    }
  }
  if ( cmax < cnt ) {
    cmax = cnt;
  }
  ans = cmax;

  cout << ans << endl;

}
