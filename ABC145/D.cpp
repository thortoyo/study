#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 1000000;
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
  
  ll X,Y;
  cin >> X >> Y;
  if ( (X+Y) % 3 != 0 ) {
    cout << "0" << endl;
    return 0;
  }
  ll cnt = (X+Y) / 3;
  X -= cnt;
  Y -= cnt;
  if ( (X < 0) || ( Y < 0) ) {
    cout << "0" << endl;
    return 0;
  }

  cout << COM(X+Y,Y) << endl;
}
