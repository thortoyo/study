#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// 上端から順に貪欲で処理
// 左から順番にみていって、奇数が2つ出てきたら、その2つの間を移動させる
// 奇数が余れば、一つ下の行に奇数を移動させる。移動先の偶奇を反転させる
// 最終行ならもう下がないので、移動はさせない

int ans[510*510][4];

int main() {
  int H,W;
  cin >> H >> W;
  vector< vector< int > > a( H, (vector<int>)(W) );
  REP(y,H) {
    REP(x,W) {
      cin >> a[y][x];
      a[y][x] = a[y][x] % 2;
    }
  }
  int n = 0;
  REP(y,H) {
    int pre_o = -1;
    REP(x,W) {
      if ( a[y][x] == 1 ) {
        if (pre_o != -1) {
          for( int i=pre_o; i<x; i++ ) {
            ans[n][0] = y;
            ans[n][1] = i;
            ans[n][2] = y;
            ans[n][3] = i+1;
            n++;
          }
          pre_o = -1;
        } else {
          pre_o = x;
        }
      }
    }
    if ((pre_o != -1) && (y!=H-1)) {
      ans[n][0] = y;
      ans[n][1] = pre_o;
      ans[n][2] = y+1;
      ans[n][3] = pre_o;
      n++;
      a[y+1][pre_o] = (a[y+1][pre_o]==0) ? 1 : 0;
    }
  }
  cout << n << endl;
  REP(i,n) {
    cout << (ans[i][0]+1) << " " << (ans[i][1]+1) << " " << (ans[i][2]+1) << " " << (ans[i][3]+1) << endl;
  }
}

