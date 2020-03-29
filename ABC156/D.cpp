#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 300000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  // 前処理
  COMinit();
  
  ll n,a,b;
  cin >> n >> a >> b;
  // 2^n 計算
  ll nn = n;
  ll n2 = 1;
  ll tmp = 2;
  while(nn) {
    if (nn&1) n2 = n2 * tmp % MOD;
    tmp = tmp * tmp % MOD;
    nn /= 2;
  }
  ll ans = n2 - 1;
  if (ans < 0) ans += MOD;
  // COM(n,a)
  ll nca = 1;
  REP(i,a) {
    nca = nca * (n-i) % MOD;
  }
  nca = nca * finv[a] % MOD;
  // COM(n,b)
  ll ncb = 1;
  REP(i,b) {
    ncb = ncb * (n-i) % MOD;
  }
  ncb = ncb * finv[b] % MOD;
  ans -= nca;
  if ( ans<0) ans += MOD;
  ans -= ncb;
  if ( ans<0) ans += MOD;
  cout << ans << endl;
//  cout << n2 << " " << nca << " " << ncb << endl;
}

