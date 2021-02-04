#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 2000000;
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

// 順列計算
long long PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
}

int main(){
  ll N,M;
  cin >> N >> M;
  COMinit();

  // A = 1,2,3,..,N に固定して考える
  // B の組み合わせ数は何も条件がないなら PER(M, N)
  // 少なくとも i 個の A と B が一致している場合は、PER(M-i, N-i)
  // i 個の一致がある場合の組み合わせは COM(M, i)
  // 包徐原理で i 奇数は引く、偶数は足す
  //  i=0 の場合は、全条件不定なので全事象の数になるので ＋ 
  //  i=1 の場合を上記全事象から引くので  ー
  // 固定していた A の組み合わせ数は PER(M ,N)
  ll ans = 0;
  for( ll i=0; i<=N; i++ ) {
    ll c = PER(M-i, N-i);
    c = c * COM(N, i) % MOD;
    if ( i&1 == 1 ) c = -c;
    ans = (ans + c) % MOD;
    if ( ans < 0 ) ans += MOD;
//    cout << i << " : " << ans << endl;
  }
  ans = ans * PER(M,N) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
