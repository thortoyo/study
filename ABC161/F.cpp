#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll pnum = 0;
ll ans = 0;
vector<pair<ll, ll> > res;

void prime_factorize(ll N) {
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // Žw”

        // Š„‚ê‚éŒÀ‚èŠ„‚è‘±‚¯‚é
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // ‚»‚ÌŒ‹‰Ê‚ð push
        res.push_back({a, ex});
    }

    // ÅŒã‚ÉŽc‚Á‚½”‚É‚Â‚¢‚Ä
    if (N != 1) res.push_back({N, 1});
    return;
}

void chk( int num, ll a, ll N ) {
  cout << "chk " << num << " " << a << " " << N << endl;
  if ( num == pnum ) {
    ll b = N / a;
    if ( N % a == 1 ) ans++;
  } else {
    REP(i,res[num].second) {
      chk(num+1, a*(i+1), N );
    }
  }
  return;
}

int main() {
  ll N;
  cin >> N;
  prime_factorize(N);
  for (auto p : res) {
    pnum++;
    cout << p.first << " : " << p.second << endl;
  }
  cout << " pnum: " << pnum << endl;
  chk(0, 1, N);
  cout << ans <<endl;
}


