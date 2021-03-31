#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

// DFS‚Å‘“–‚½‚è

int A,B,H,W;
bool used[16][16];
ll ans;

void DFS(int y, int x, int a) {
//  cout << y << " " << x << " " << a << " : " << ans << endl;
  if ( y==H ) {
    if ( a != A ) return;
    ans++;
    return;
  }
  if ( used[y][x] ) {
    if ( x+1 == W )   DFS( y+1, 0, a );
    else  DFS( y, x+1, a );
    return;
  }

  // c’u‚«
  if ( y < H-1 && a < A ) {
    used[y][x] = used[y+1][x] = true;
    if ( x+1 == W ) 
      DFS( y+1, 0, a+1 );
    else
      DFS( y, x+1, a+1 );
    used[y][x] = used[y+1][x] = false;
  }

  // ‰¡’u‚«
  if ( x < W-1 && a < A && !used[y][x+1] ) {
    used[y][x] = used[y][x+1] = true;
    DFS( y, x+1, a+1 );
    used[y][x] = used[y][x+1] = false;
  }

  // ”¼ô
  used[y][x] = true;
  if ( x+1 == W )   DFS( y+1, 0, a );
  else  DFS( y, x+1, a );
  used[y][x] = false;

  return;
}


ll solve() {
  cin >> H >> W >> A >> B;
  DFS(0,0,0);
  return ans;
}

int main(){
  cout << solve() << endl;
}
