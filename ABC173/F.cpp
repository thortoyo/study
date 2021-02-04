#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 2000005;
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

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  // 前処理
  COMinit();
  
  ll K;
  cin >> K;
  string S;
  cin >> S;
  ll slen = S.length();
  ll ans = 0;
  REP(i,K+1) {
    // Sの最後の文字より手前に i 文字挿入している場合
    // Sの最後の文字より後は自由なので 26^(K-i)
    // Sの最後の文字より前は、25^(i)
    // Sを全体の部分文字列として、その部分列が最短で見つける場合の貪欲処理の反対を考える
    ll knum = modpow(25, i, MOD);
    knum = (knum * modpow(26, K-i, MOD)) % MOD;
    knum = (knum * COM( i+slen-1, slen-1)) % MOD;
    ans = (ans + knum) % MOD;
//    cout << knum << " : " << ans << endl;
  }
  cout << ans << endl;
}
