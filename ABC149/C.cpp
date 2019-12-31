#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<bool> IsPrime(110000,true);

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
  ll X;
  cin >> X;
  sieve(110000);
  int i = X;
  for ( ; !IsPrime[i]; ++i );
  cout << i << endl;
}
