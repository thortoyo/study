#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int H,K,W;
  cin >> H >> W >> K;
  vector< string > S(H);
  REP(i,H) cin >> S[i];

  int ans = 1000000;
  REP(i, 1 << (H-1) ) {
    int cn = 0;
    vector< int > cut(H,0);
    int hn = 0;
    REP(j,H-1) {
      if ( (i & ( 1 << j)) != 0 ) {
        hn++;
        cn++;
      }
      cut[j+1] = hn;
    }
    bool imp = false;
    vector< int > cnt(hn+1, 0);
    int xn = 0;
    REP(x,W) {
      REP(y,H) {
        if (S[y][x] == '1' ) cnt[ cut[y] ]++;
      }
      xn++;
      REP(k,hn+1) {
        if ( cnt[k] > K ) {
          if ( xn == 1 ) { imp = true; cn = 1000000; break; }
          cn++;
          REP(l, hn+1) cnt[l] = 0;
          x--;
          xn = 0;
          break;
        }
      }
      if ( imp ) break;
    }
//    cout << i << " : " << cn << endl;
    ans = min(ans, cn);
  }
  cout << ans << endl;
}



