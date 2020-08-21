#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  REP(i,N) cin >> A[i];
  A[N] = 0;
  bool pos = false;
  ll k = 0;
  ll ans = 1000;
  REP(i,N) {
    if ( pos ) {
      // è„è∏íÜ
      if ( A[i+1] < A[i] ) {
        ans += k * A[i];
        pos = false;
      }
    } else {
      // â∫ç~íÜ
      if ( A[i+1] > A[i] ) {
        k = ans / A[i];
        ans -= k * A[i];
        pos = true;
      }
    }
  }
  cout << ans << endl;
}
