#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
  if ( a%b==0 ) return b;
  return GCD(b, a%b);
}
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];
  REP(i,N-1) {
    A[i+1] = GCD(A[i], A[i+1]);
  }
  cout << A[N-1] << endl;
}
