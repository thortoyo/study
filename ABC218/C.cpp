#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;




void solve() {
  int N;
  cin >> N;
  vector<string> S(N), T(N);
  REP(i,N)  cin >> S[i];
  REP(i,N)  cin >> T[i];

  // 左上と右下
  int s_st_y(N+1),s_st_x(N+1), s_ed_y(-1), s_ed_x(-1);
  int t_st_y(N+1), t_st_x(N+1), t_ed_y(-1), t_ed_x(-1);
  int s_num=0, t_num=0;
  REP(y,N) {
    REP(x,N) {
      if ( S[y][x] == '#' ) {
        s_st_x = min(x, s_st_x);
        s_st_y = min(y, s_st_y);
        s_ed_x = max(x, s_ed_x);
        s_ed_y = max(y, s_ed_y);
        s_num++;
      }
      if ( T[y][x] == '#' ) {
        t_st_x = min(x, t_st_x);
        t_st_y = min(y, t_st_y);
        t_ed_x = max(x, t_ed_x);
        t_ed_y = max(y, t_ed_y);
        t_num++;
      }
    }
  }
//  cout << s_st_x << " " << s_st_y << " " << t_st_x << " " << t_st_y << endl;
//  cout << s_ed_x << " " << s_ed_y << " " << t_ed_x << " " << t_ed_y << endl;

  if ( s_num != t_num ) {
    cout << "No" << endl;
    return;
  }
  REP(i,4) {
    int ng = 0;
    for ( int sy = 0; sy<=(s_ed_y-s_st_y); sy++ ) {
      for ( int sx = 0; sx<=(s_ed_x-s_st_x); sx++ ) {
        int ty, tx;
        switch(i) {
        case 0:		// T をそのまま
          ty = sy + t_st_y;
          tx = sx + t_st_x;
          break;
        case 1:		// T を反時計回りに90度回転
          ty = t_st_y + sx;
          tx = t_ed_x - sy;
          break;
        case 2:		// T を反時計回りに180度回転
          ty = t_ed_y - sy;
          tx = t_ed_x - sx;
          break;
        default:		// T を反時計回りに270度回転
          ty = t_ed_y - sx;
          tx = t_st_x + sy;
          break;
        }
        if ( ty < 0 || tx < 0 ) { ng = 1; break;}
        if ( S[s_st_y+sy][s_st_x+sx] != T[ty][tx] ) { ng = 1; break;}
      }
    }
    if ( ng == 0 ) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
  return;
}

int main(){
  solve();
}


