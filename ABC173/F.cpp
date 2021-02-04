#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 2000005;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// �e�[�u�������O����
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

// �񍀌W���v�Z
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// ����v�Z
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
  // �O����
  COMinit();
  
  ll K;
  cin >> K;
  string S;
  cin >> S;
  ll slen = S.length();
  ll ans = 0;
  REP(i,K+1) {
    // S�̍Ō�̕�������O�� i �����}�����Ă���ꍇ
    // S�̍Ō�̕�������͎��R�Ȃ̂� 26^(K-i)
    // S�̍Ō�̕������O�́A25^(i)
    // S��S�̂̕���������Ƃ��āA���̕����񂪍ŒZ�Ō�����ꍇ���×~�����̔��΂��l����
    ll knum = modpow(25, i, MOD);
    knum = (knum * modpow(26, K-i, MOD)) % MOD;
    knum = (knum * COM( i+slen-1, slen-1)) % MOD;
    ans = (ans + knum) % MOD;
//    cout << knum << " : " << ans << endl;
  }
  cout << ans << endl;
}
