#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,K;
  cin >> N >> K;

  vector<int> A(N);
  vector<int> AA(N,0);
  vector<int> GCD(N,0);
  int64_t at = 0;
  for( int64_t i=0; i<N; ++i) {
    cin >> A[i];
    at += A[i];
  }

  sort( A.begin(), A,end() );
  AA[i] = A[i];
  for( int i=1; i<N; i++ ) {
    AA[i] = A[i] + AA[i-1];
  }

  for( int i=0; i<N; i++ ) {


  cout << endl;

}
