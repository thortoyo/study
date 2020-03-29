#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

const int MAX = 110000;
const int MOD = 1000000007;

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

  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];
  sort(A.begin(), A.end());
  // MIN/MAX合計
  ll minsum = 0;
  ll maxsum = 0;
  REP(i,N-K+1) {
    ll combi = COM( N-1-i, K-1 ) % MOD;
    minsum += A[i] * combi % MOD;
    maxsum += A[N-1-i] * combi % MOD;
  }
  cout << ((maxsum + MOD) - minsum) %MOD << endl;
}
