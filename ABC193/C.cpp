#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll solve() {
  ll N;
  cin >> N;
  set<ll> use;
  ll ans = 0;
  for (ll a=2; a*a<=N; a++ ) {
    if ( use.count(a) == 1 ) continue;
    for (ll b=a*a; b<=N; b*=a ) {
      ans++;
      use.insert(b);
    }
  }
  return N-ans;
}

int main(){
  cout << solve() << endl;
}
