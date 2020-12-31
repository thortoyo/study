#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// 	Kx + S = 0 (mod  N)
// 	Kx = -S (mod N)
// 
// K �� N ���݂��ɑf�Ȃ� K * K^(-1) = 1(mod N) �ƂȂ�t�������݂���
// 	x = - K^(-1) S (mod N)
// 
// K �� N ���݂��ɑf�łȂ��Ȃ�A
// 	Kx = -S (mod N)
// 	Kx + S = Ny
// g = GCD(K,N) �Ƃ���ƁA
// 	S = Ny - Kx = g(ny - kx)
// �Ȃ̂ŁAS �� g �̔{���ł���K�v������B
// 
// �{���łȂ���΁AKx = -S (mod N) �͖������Ȃ��B�� ���Ȃ�
// �{���Ȃ�A
// 	Kx + S = Ny
// 	gkx + gs = gny
// 	kx + s = ny
// 	kx = -s (mod n)
// �ƂȂ��āAK��S��N�� g �Ŋ����������ŐV���Ɏ������

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
