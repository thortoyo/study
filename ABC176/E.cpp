#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int ch[300010];
int cw[300010];

int main(){
  int H,W,M;
  cin >> H >> W >> M;
  set< pair<int, int> > blk;
  REP(i,M) {
    int h,w;
    cin >> h >> w;
    h--; w--;
    blk.emplace(h,w);
    ch[h]++;
    cw[w]++;
  }
  int maxh = 0;
  int maxw = 0;
  REP(i,H) maxh = max( maxh, ch[i] );
  REP(i,W) maxw = max( maxw, cw[i] );

  vector<int> lh, lw;
  int ans = maxh + maxw - 1;
  REP(i,H) if ( ch[i] == maxh ) lh.emplace_back( i );
  REP(i,W) if ( cw[i] == maxw ) lw.emplace_back( i );
  for ( auto h : lh ) {
    int f = 0;
    for ( auto w : lw ) {
      if ( blk.find( make_pair(h,w) ) == blk.end() ) {
        f = 1;
        ans++;
        break;
      }
    }
    if (f==1) break;
  }
  
  cout << ans << endl;
}
