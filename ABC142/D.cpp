#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

// n ‚Ì–ñ”‚ğ—ñ‹“
vector<ll> enum_div(ll n) {
  vector<ll> ret;
  ll sn = sqrt(n);
  for(ll i=1 ; i<=sn ; ++i) {
    if(n%i == 0) {
      ret.push_back(i);
      if(i!=(n/i) && i*i!=n)
        ret.push_back(n/i);
    }
  }
  return ret;
}

vector<bool> IsPrime;

void sieve(ll max){
  if(max+1 > IsPrime.size()){     // resize‚Å—v‘f”‚ªŒ¸‚ç‚È‚¢‚æ‚¤‚É
    IsPrime.resize(max+1,true); // IsPrime‚É•K—v‚È—v‘f”‚ğŠm•Û
  } 
  IsPrime[0] = false; // 0‚Í‘f”‚Å‚Í‚È‚¢
  IsPrime[1] = false; // 1‚Í‘f”‚Å‚Í‚È‚¢

  ll smax = sqrt(max);
  for(ll i=2; i<=smax; ++i) // 0‚©‚çsqrt(max)‚Ü‚Å’²‚×‚é
    if(IsPrime[i]) // i‚ª‘f”‚È‚ç‚Î
      for(ll j=2; i*j<=max; ++j) // (maxˆÈ‰º‚Ì)i‚Ì”{”‚Í
        IsPrime[i*j] = false;      // ‘f”‚Å‚Í‚È‚¢
}

int main() {
  ll A,B;
  cin >> A >> B;

  ll g = gcd(A,B);
//  cout << g << endl;
  vector<ll> gv = enum_div(g);
//  for ( auto x: gv ) cout << x << " ";
//  cout << endl;
  ll gvsize = gv.size();

  sieve(g);

  ll cnt = 0;
  REP(i,gvsize) {
    if ( IsPrime[gv[i]] ) cnt++;
  }
  cout << cnt+1 << endl;
}
