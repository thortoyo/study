#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;



int main(){
  int N, Q;
  cin >> N;
  vector<ll> A(N);
  map<ll,ll> M;
  REP(i,N) {
    cin >> A[i];
    M[A[i]]++;
  }
  ll ans = 0;
  for ( auto m : M) {
    ans += ( m.first * m.second);
  }
  cin >> Q;
  REP(i,Q) {
    ll B, C;
    cin >> B >> C;
    ll mb = M[B];
    ll mc = M[C];
    M[C] += mb;
    M[B] = 0;
    ans -= mb * B;
    ans += mb * C;
    cout << ans << endl;
  }

}
