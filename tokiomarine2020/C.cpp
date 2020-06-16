#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  REP(i,N) cin >> A[i];

  int i = 1;
  REP(i,K-1) {
   if (i >= N) break;
    i *= 2;
  }
  if (i >= N) {
    REP(i,N) cout << N << " ";
    cout << endl;
  } else {
    REP(i,K) {
      REP(j,N) B[j] = 1;
      REP(j,N) {
        REP(k,A[j]) {
          if ( j-k-1 >= 0 )  B[j-k-1]++;
          if ( j+k+1 < N )  B[j+k+1]++;
        }
        //      REP(i,N) cout << B[i] << " ";
        //      cout << endl;
      }
      swap(A,B);
    }
    REP(i,N) cout << A[i] << " ";
    cout << endl;
  }
}
