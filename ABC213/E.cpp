#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

//�ǂ��󂷂̂�1x1�Ȃ�A�Ǖ����ɐi�ގ��̃R�X�g��1�ɂ��āA�_�C�N�X�g����OK
//���̖��̏ꍇ2x2�Ȃ̂ŁA�󂵂��ꍇ�ɃR�X�g1�Ŕ�ׂ�͈�
//
//�󂷌��̌��
//	 x
//	x@x
//	 x
//
//2x2�͈͂ŉ󂷂̂ŁA�Ⴆ�Έȉ��̗l��4�}�X�̓R�X�g1�ōs����悤�ɂȂ�B
//	 xx
//	 xx
//	 @
//
//	xx
//	xx
//	 @
//
//	  xx
//	 @xx
//
//�܂�ȉ��̏ꏊ�ɃR�X�g1�ōs���}�𒣂��OK
//	 xxx
//	xxxxx
//	xx@xx
//	xxxxx
//	 xxx


const int dx[4] = { 0,  0, -1, 1};
const int dy[4] = { 1, -1,  0, 0};
const int d2x[20] = {-1, 0, 1,-2,-1, 0, 1, 2,-2,-1, 1, 2,-2,-1, 0, 1, 2,-1, 0, 1};
const int d2y[20] = {-2,-2,-2,-1,-1,-1,-1,-1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};

int dp[501][501];
vector< vector< vector< tuple<int,int,int> > > > to(501, (vector< vector< tuple<int,int,int> > >(501)));

void dbgprint(int h, int w) {
  REP(y, h) {
    REP(x,w) {
      if (dp[y][x] == 1<<30) cout << "INF ";
      else printf("%3d ",dp[y][x]);
    }
    cout << endl;
  }
}

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> S(1000);
  REP(i,H) {
    string a;
    cin >> S[i];
  }
  dp[0][0] = 0;
  REP(y,H) {
    REP(x,W) {
      REP(d, 4) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if ( (ny < 0) || (nx < 0) || (ny >= H) || (nx >= W) ) continue;
        if ( S[ny][nx] == '.' ) 
          to[y][x].emplace_back(0,ny,nx);
      }
      REP(d, 20) {
        int ny = y + d2y[d];
        int nx = x + d2x[d];
        if ( (ny < 0) || (nx < 0) || (ny >= H) || (nx >= W) ) continue;
        to[y][x].emplace_back(1,ny,nx);
      }
    }
  }

  REP(y, 501) REP(x,501) dp[y][x] = 1 << 30;
  
  priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > q;
  q.push( {0, 0, 0} );
  dp[0][0] = 0;
  while( !q.empty() ) {
    int c, y, x;
    tie(c, y, x) = q.top(); q.pop();
//    dbgprint(H, W);
    for ( auto ns : to[y][x] ) {
      int d, ny, nx;
      tie(d, ny, nx) = ns;
//      printf("%d,%d : %d %d,%d\n",x,y,d,nx,ny);
      if ( dp[ny][nx] > dp[y][x] + d ) {
        dp[ny][nx] = dp[y][x] + d;
        q.emplace( dp[ny][nx], ny, nx );
      }
    }
  }
  cout << dp[H-1][W-1] << endl;
  return;
}



int main(){
  solve();
}
