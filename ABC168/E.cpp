#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
 
map< pair<ll,ll> , int > m;
ll p2[202020];

ll GCD(ll a, ll b) {
  if ( a%b==0 ) return b;
  return GCD(b, a%b);
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
  p2[0] = 1;
  REP(i,202020) p2[i+1] = (p2[i] * 2) % MOD;
  
  int N;
  cin >> N;
  ll ans = 1;
  int z = 0;
  REP(i,N) {
    ll a,b;
    cin >> a >> b;
    if (a==0 && b==0) {
      z++;
    } else if (a==0) {
      m[{0,-1}]++;
    } else if (b==0) {
      m[{1,0}]++;
    } else {
      ll gcd = GCD(abs(a),abs(b));
      a /= gcd;
      b /= gcd;
      if (a<0) {
        a = -a;
        b = -b;
      }
      m[{a,b}]++;
    }
  }
  for ( auto m0 : m ) {
//    cout << m0.first.first << " " << m0.first.second << " " << m0.second << " " << ans << endl;
    ll a0 = m0.first.first;
    ll b0 = m0.first.second;
    ll a1,b1, t = 1;
    if ( m[{a0,b0}] != 0 ) {
      if ( b0<0 ) {
        a1 = -b0;
        b1 = a0;
      } else {
        a1 = b0;
        b1 = -a0;
      }
//      t = (modpow(2, m[{a0,b0}], MOD) + modpow(2, m[{a1,b1}], MOD) - 1) % MOD;
      t = (p2[m[{a0,b0}] ] + p2[m[{a1,b1}]]- 1) % MOD;
      m[{a1,b1}] = 0;
    }
    m[{a0,b0}] = 0;
    ans = (ans * t)% MOD;
  }
  cout << ((ans+z+MOD-1)%MOD) << endl;
}

