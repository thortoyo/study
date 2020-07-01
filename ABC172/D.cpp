#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i=1;i<=N;++i) {
    for(ll j=i;j<=N; j+=i) {
      ans += j;
    }
  }
  cout << ans << endl;

}
