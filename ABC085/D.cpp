#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,H;
  cin >> N >> H;
  vector< pair<int, int> > ab;
  REP(i, N) {
    int a,b;
    cin >> a >> b;
    ab.emplace_back( a, 0 );
    ab.emplace_back( b, 1 );
  }
  sort( ab.begin(), ab.end(),greater<pair<int,int> >() );
  ll ans = 0;
  for (int i=0; H>0; i++ ) {
    if (ab[i].second == 0) {
      ans += (H+ab[i].first-1) / ab[i].first;
      break;
    } else {
      ans += 1;
      H -= ab[i].first;
    }
  }
  cout << ans << endl;
}
