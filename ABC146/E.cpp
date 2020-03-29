// Ai �� A-1 �ɒu��������ƁA�����a%K = 0 �𐔂�����ɂȂ�B
// �����a�����߂邽�߂ɗݐϘa�����B
// (R[j] - R[i])%K = 0 �Ȑ��𐔂���̂ŁAR[j]%K == R[i]%K �𐔂����OK�B

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
