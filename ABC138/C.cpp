#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  vector<int> v(N);
  for( int i=0; i<N; ++i) {
    cin >> v[i];
  }

  sort( v.begin(), v.end() );

  double ans = (double)v[0];
  for (int i=0; i<N-1; ++i ) {
    ans = (ans + (double)v[i+1]) / 2;
  }

  cout << ans<< endl;

}
