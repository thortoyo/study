#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,M;
  cin >> N >> M;
  multiset<int> A;
  REP(i,N) {
    int ain;
    cin >> ain;
    A.emplace(ain);
  }
  REP(i,M) {
    auto ait = A.end();
    ait--;
    int amax = *ait;
    A.erase(ait);
    A.emplace( amax>>1 );
  }
  ll ans = 0;
  for( auto x: A ) {
    ans += x;
  }
  cout << ans << endl;
}
