#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,A;
  cin >> N;
  vector< vector< pair<int,int> > > s(N);
  REP(i,N) {
    cin >> A;
    REP(j,A) {
      int x,y;
      cin >> x >> y;
      s[i].emplace_back( --x, y );
    }
  }

  int ans = 0;
  // ‘S’Tõ
  REP(t,1 << N) {
    int ng = 0;
    REP(i,N) {
      if ( ((t >> i) & 1) == 1 ) {
        for ( auto x: s[i] )
          if ( ((t >> x.first) & 1) != x.second ) ng = 1;
      }
    }
    if ( ng == 0 ) {
      int cnt = 0;
      REP(i,N) if (((t >> i) & 1)==1) cnt++;
      ans = max(ans,cnt);
    }
  }
  cout << ans << endl;

  return 0;
}
