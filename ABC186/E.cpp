#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// 	Kx + S = 0 (mod  N)
// 	Kx = -S (mod N)
// 
// K と N が互いに素なら K * K^(-1) = 1(mod N) となる逆元が存在する
// 	x = - K^(-1) S (mod N)
// 
// K と N が互いに素でないなら、
// 	Kx = -S (mod N)
// 	Kx + S = Ny
// g = GCD(K,N) とすると、
// 	S = Ny - Kx = g(ny - kx)
// なので、S も g の倍数である必要がある。
// 
// 倍数でなければ、Kx = -S (mod N) は満たさない。→ 解なし
// 倍数なら、
// 	Kx + S = Ny
// 	gkx + gs = gny
// 	kx + s = ny
// 	kx = -s (mod n)
// となって、KとSとNを g で割った数字で新たに式を作る

ll GCD(ll a, ll b) {
  if ( a%b==0 ) return b;
  return GCD(b, a%b);
}

ll solve() {
  ll N,S,K;
  cin >> N >> S >> K;
  ll g = GCD(N,K);
  if (S%g != 0) return -1;
  N /= g;
  S /= g;
  K /= g;
  modint::set_mod(N);
  modint x = - modint(S) / modint(K);
  return x.val();
}

int main(){
  int T;
  cin >> T;
  REP(i,T) {
    cout << solve() << endl;
  }
}
