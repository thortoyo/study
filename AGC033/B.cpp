#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int H,W,N,iy,ix;
  string S,T;
  cin >> H >> W >> N >> iy >> ix >> S >> T;
  ix--; iy--;
  int l = -1, r = W, u = -1, d = H;
  bool flg = false;
  for( int i=N-1; i>=0; --i ) {
    if ( i !=N-1 ) {
      if (T[i] == 'L' ) r = min(r+1, W);
      else if (T[i] == 'R' ) l = max(-1,l-1);
      else if (T[i] == 'U' ) d = min(d+1, H);
      else u = max(-1, u-1);
    }
    if (S[i] == 'L' ) l++;
    else if (S[i] == 'R' ) r--;
    else if (S[i] == 'U' ) u++;
    else d--;
//    cout << " " << i << " : " << l << " " << r << " " << u << " " << d << endl;
//    if ( (l >= W) || (r<=0) || (u>=H) || (d<=0) ) {
    if ( (l+1 >= r) || (u+1 >= d) ) {
      flg = true;
      break;
    }
  }
  if ( flg ) {
    cout << "NO" << endl;
  } else if ( (l >= ix) || (r <= ix) || (u >= iy) || (d <= iy) ) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

