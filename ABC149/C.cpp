#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<bool> IsPrime(110000,true);

void sieve(ll max){
  if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
    IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
  } 
  IsPrime[0] = false; // 0は素数ではない
  IsPrime[1] = false; // 1は素数ではない

  ll smax = sqrt(max);
  for(ll i=2; i<=smax; ++i) // 0からsqrt(max)まで調べる
    if(IsPrime[i]) // iが素数ならば
      for(ll j=2; i*j<=max; ++j) // (max以下の)iの倍数は
        IsPrime[i*j] = false;      // 素数ではない
}

int main() {
  ll X;
  cin >> X;
  sieve(110000);
  int i = X;
  for ( ; !IsPrime[i]; ++i );
  cout << i << endl;
}
