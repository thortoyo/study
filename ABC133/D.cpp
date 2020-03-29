#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for( int64_t i=0; i<N; ++i) {
    cin >> A[i];
  }

  int64_t m1 = 0;
  for( int64_t i=0; i<N; ++i) {
    if (i%2==0) m1 += A[i];
    else m1 -= A[i];
  }
  m1 /= 2;
  cout << m1*2;

  int64_t m = m1;
  for( int64_t i=0; i<N-1; ++i) {
    m = A[i] - m;
    cout << " " << m*2;
  }
}
