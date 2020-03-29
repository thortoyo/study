#include <iostream>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// 単純に範囲内の各座標の C を足すのは 10^6まで範囲があるので、 10^12 で全くもってNG
// 工夫して計算量を抑える必要がある。
// ある座標での経路総数を f(x,y) とすると
// 	f(a+1,b) = f(a,0) + f(a,1) +  f(a,2) + ... + f(a,b)
// らしい。
// 	3  ─〇 ← (a+1, 3)
// 	2  ─┤
// 	1  ─┤
// 	0  ─┘
// 	  a  a+1
// となると、(a+1, 4) に行く経路は (a,0),(a,1),(a,2),(a,3) の合計になる。
// ということは求める長方形に上辺の各値を計算したら、その一つ左の列の縦全部を加算した値がわかる。
// 求める長方形の下辺の一個下の各値を計算して引いてやると、長方形の中身の合計がわかる。
// 上辺の各値の加算も、上記のxとyとが逆になった版と考えることができて、
// 上辺の右端+1 までの合計値は、上辺の右端+1をさらに一個上に行った座標の値になる。
// よって範囲が 横 r1 ～ r2、縦 c1 ～ c2 なので、
// 	f(r2+1, c2+1) - f(r1, c2+1) - f(r2+1, c1) + f(r1+1,c1+1)
// で計算できる。

const int MAX = 2000005;
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

  ll r1,r2,c1,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  // f(r2+1, c2+1) - f(r1, c2+1) - f(r2+1, c1) + f(r1+1,c1+1)
  ll ans = (COM( r2+1+c2+1, c2+1 ) + COM( r1+c1, c1 )) % MOD;
  ans -= COM( r1+c2+1, c2+1 );
  ans = (ans<0) ? ans + MOD : ans;
  ans -= COM( r2+1+c1, c1 );
  ans = (ans<0) ? ans + MOD : ans;
  cout << ans << endl;
}

