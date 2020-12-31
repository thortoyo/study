#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N,0);
  REP(i,N) cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  B[0] = A[0];
  for(int i=1; i<N; i++ ) {
    B[i] = B[i-1] + A[i];
  }
  for(int i=N-1; i>0; i-- ) {
    ans += (A[i]*i - B[i-1]);
//    cout << A[i]*i << " " << B[i-1] << " " << (A[i]*i - B[i-1]) << " " << ans << endl;
  }

  cout << ans << endl;
}
