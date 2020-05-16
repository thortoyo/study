#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// mod(2*K) ‚Ì‹óŠÔ‚É‚µ‚ÄA2ŸŒ³—İÏ˜a‚·‚éB
// K=3
// 	        x
// 	  0 1 2 3 4 5 6
// 	0 0 0 0|0 0 0|0
// 	1 0 # #|     |#
// 	  -----+-----+-
// y	2 0    |# # #| 
// 	3 0    |# # #| 
// 	4 0    |# # #| 
// 	  -----+-----+-
// 	5 0 # #|     |#
// 	6 0 # #|     |#


int bk[2020][2020];

int main() {
  int N, K;
  cin >> N >> K;
  REP(i,N) {
    int x,y; char c;
    cin >> x >> y >> c;
    // ”’‚ÍK‚¸‚ç‚µ‚Ä•‚É‚·‚é
    if (c == 'W') y += K;
    bk[ (x%(2*K))+1 ][ (y%(2*K))+1 ]++;
  }
  // “ñŸŒ³—İÏ˜a
  for (int y=1; y<=2*K+1; y++)
    for (int x=1; x<=2*K+1; x++)
      bk[x][y] += bk[x][y-1];
  for (int x=1; x<=2*K+1; x++)
    for (int y=1; y<=2*K+1; y++)
      bk[x][y] += bk[x-1][y];

  int ans = 0;
  for (int y=1; y<=K; y++) {
    for (int x=1; x<=K; x++) {
      int num = bk[x-1][y-1];
      num += bk[2*K][2*K] - bk[2*K][y+K-1] - bk[x+K-1][2*K] + bk[x+K-1][y+K-1];
      num += bk[2*K][y-1] - bk[x+K-1][y-1];
      num += bk[x-1][2*K] - bk[x-1][y+K-1];
      num += bk[x+K-1][y+K-1] - bk[x+K-1][y-1] - bk[x-1][y+K-1] + bk[x-1][y-1];
      ans = max( num, ans );
      ans = max( N-num, ans );
    }
  }
  cout << ans << endl;
/*
  REP(y,2*K+1) {
    REP(x,2*K+1) {
      cout << bk[x][y] << " " ;
    }
    cout << endl;
  }
  */

}

