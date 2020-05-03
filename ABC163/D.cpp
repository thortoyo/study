#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(){
  ll N , K;
  cin >> N >> K;

  ll ans = 0;
  for ( ll i=K; i<=N+1; i++ ) {
    ll mi = (K-1+(i-K)) * i / 2;
    ll ma = (N+(N-(K-1)-(i-K))) * i / 2;
    ans = ((ma - mi + 1) + ans) % MOD;
//  cout << i << " " << mi << " " << ma << " : " << ans << endl;
  }
  cout << ans << endl;
}
