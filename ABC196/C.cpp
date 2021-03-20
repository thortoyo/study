#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll solve() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i=1; i<7; i++ ) {
    ll n=1;
    for(int j=1; j<i; j++ ) n *= 10;
    ll n10 = n * 10;
    for(ll j=n; j<n10; j++) {
      if ( (j + j * n10) <= N ) ans++;
    }
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
