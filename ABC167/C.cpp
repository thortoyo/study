#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector< vector< int > > to(100010);

int main(){
  int N,M;
  cin >> N >> M;
  vector<ll> H(N);
  REP(i,N) cin >> H[i];
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  int ans = 0;
  REP(i,N) {
    if ( to[i].size() == 0 ) {
      ans++;
    } else {
      int ok = 1;
      for ( auto v : to[i] ) {
        if ( H[i] <= H[v] ) {
          ok = 0;
          break;
        }
      }
      if ( ok == 1 ) ans++;
    }
  }

  cout << ans << endl;
}
