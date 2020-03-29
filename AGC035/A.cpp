#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  int ans=0;
  cin >> N;
  
  vector<int64_t> A(3,-1);
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  int64_t ain;
  for( int64_t i=0; i<N; ++i) {
    cin >> ain;
    if( A[0] == -1 ) {
      A[0] = ain;
      cnt0++;
    } else if( A[1] == -1 ) {
      if ( A[0] == ain) {
        cnt0++;
      } else {
        A[1] = ain;
        cnt1++;
      }
    } else if( A[2] == -1 ) {
      if ( A[0] == ain) {
        cnt0++;
      } else if ( A[1] == ain) {
        cnt1++;
      } else if ( A[0] != ain && A[1] != ain) {
        A[2] = ain;
        cnt2++;
      }
    } else {
      if ( A[0] != ain && A[1] != ain && A[2] != ain ) {
        cout << "No" << endl;
        return 0;
      }
      if ( A[0] == ain) {
        cnt0++;
      } else if ( A[1] == ain) {
        cnt1++;
      } else {
        cnt2++;
      }
    }
  }

  if((cnt0 == cnt1) && (cnt0 == cnt2) && ( (A[0] ^ A[1]) == A[2])) {
    cout << "Yes" << endl;
  } else if( (cnt2 == 0) && (((cnt0 == cnt1*2) && (A[1] == 0)) ||
                             (cnt1 == cnt0*2) && (A[0] == 0) ) ) {
    cout << "Yes" << endl;
  } else if( (cnt2 == 0) && (cnt1==0) && (A[0] == 0)){
    cout << "Yes" << endl;
  } else{ 
    cout << "No" << endl;
  }
}
