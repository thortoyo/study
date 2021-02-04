#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N,K;
//  cin >> N >> K;
  N = 200000;
  K = 199999;
  ll ans = 0;
  vector< ll > A(N);
//  REP(i, N) cin >> A[i];
  REP(i, N) A[i] = i+1;
  ll tb = 1;
  REP(i,K) tb *= A[i];
  for ( int i=K; i<N; i++ ) {
    ll t = tb / A[i-K];
    t *= A[i];
    if ( t > tb ) cout << "Yes" << endl;
    else  cout << "No" << endl;
    tb = t;
  }
}
