#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N,K;
  cin >> N >> K;
  K = abs(K);
  ll ans = 0;
  for (ll i=K+2; i<=2*N; i++ ) {
    // (a+b) - (c+d) = K ‚Æ‚·‚éBK‚Í³
    ll ab = i;
    ll cd = (i-K);
    // a b ‚Ì‘g‚Ý‡‚í‚¹”
    ll abn;
    if (ab <= N+1) abn = ab-1;
    else abn = 2 * N - ab + 1;
    // c d ‚Ì‘g‚Ý‡‚í‚¹”
    ll cdn;
    if (cd <= N+1) cdn = cd-1;
    else cdn = 2 * N - cd + 1;
    ans += abn * cdn;
  }
  cout << ans << endl;
}
