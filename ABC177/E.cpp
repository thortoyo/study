#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int prime[1000009];

// ‘fˆö”•ª‰ð
void prime_factorize(long long N) {
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        // Š„‚ê‚éŒÀ‚èŠ„‚è‘±‚¯‚é
        while (N % a == 0) {
            N /= a;
        }
        prime[a]++;
    }
    // ÅŒã‚ÉŽc‚Á‚½”‚É‚Â‚¢‚Ä
    if (N != 1) prime[N]++;
    return;
}

int main(){
  int N;
  cin >> N;
  REP(i,N) {
    ll a;
    cin >> a;
    prime_factorize(a);
  }
//  for (int i=2; i<20; i++ ) cout << i << " : " << prime[i] << endl;
  int ans = 0;
  for (int i=2; i<1000001; i++ ) {
    if (prime[i] == 0) continue;
    if (prime[i] == N) {
      ans = 2;
      break;
    }
    if (prime[i] > 1) ans = 1;
  }
  if (ans == 0) cout << "pairwise coprime" << endl;
  else if (ans == 2)  cout << "not coprime" << endl;
  else  cout << "setwise coprime" << endl;
}
