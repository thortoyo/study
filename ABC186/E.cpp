#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// 	Kx + S = 0 (mod  N)
// 	Kx = -S (mod N)
// 
// K ‚Æ N ‚ªŒÝ‚¢‚É‘f‚È‚ç K * K^(-1) = 1(mod N) ‚Æ‚È‚é‹tŒ³‚ª‘¶Ý‚·‚é
// 	x = - K^(-1) S (mod N)
// 
// K ‚Æ N ‚ªŒÝ‚¢‚É‘f‚Å‚È‚¢‚È‚çA
// 	Kx = -S (mod N)
// 	Kx + S = Ny
// g = GCD(K,N) ‚Æ‚·‚é‚ÆA
// 	S = Ny - Kx = g(ny - kx)
// ‚È‚Ì‚ÅAS ‚à g ‚Ì”{”‚Å‚ ‚é•K—v‚ª‚ ‚éB
// 
// ”{”‚Å‚È‚¯‚ê‚ÎAKx = -S (mod N) ‚Í–ž‚½‚³‚È‚¢B¨ ‰ð‚È‚µ
// ”{”‚È‚çA
// 	Kx + S = Ny
// 	gkx + gs = gny
// 	kx + s = ny
// 	kx = -s (mod n)
// ‚Æ‚È‚Á‚ÄAK‚ÆS‚ÆN‚ð g ‚ÅŠ„‚Á‚½”Žš‚ÅV‚½‚ÉŽ®‚ðì‚é

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
