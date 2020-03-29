// Ai を A-1 に置き換えると、部分和%K = 0 を数える問題になる。
// 部分和を求めるために累積和を作る。
// (R[j] - R[i])%K = 0 な数を数えるので、R[j]%K == R[i]%K を数えればOK。

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll R[200005];
ll A[200005];

int main() {
  ll N, K;
  cin >> N >> K;
  R[0] = 0;
  for(int i=1; i<=N; i++) {
    cin >> A[i];
    R[i] = R[i-1] + A[i] - 1;
  }
//  REP(i,N+1) cout << R[i] << " ";
//  cout << endl;
  ll ans = 0;
  map<ll,ll> M;
  M[0] = 1;
  for(int i=1; i<=N; i++) {
    if ( i-K >= 0 ) M[ R[i-K]%K ]--;
    ans += M[ R[i]%K ];
    M[ R[i]%K ]++;
  }
//  for ( auto x: M ) cout << x.first << " " << x.second << endl;
  cout << ans << endl;
}
