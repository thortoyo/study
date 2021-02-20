#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

const ll INF = 1123456789;
const ll MOD = 998244353;

using mint = modint998244353;

char map[5005][5005];
mint sum[5005][5005];

int solve() {
  int H,W,K;
  cin >> H >> W >> K;
  REP(i,H) REP(j,W) map[i][j] = '.';
  REP(i,H) REP(j,W) {
    int h,w; char c;
    cin >> h >> w >> c;
    h--; w--;
    map[h][w] = c;
  }
  if (map[H-1][W-1] == '.') sum[H-1][W-1] = 3;
  else  sum[H-1][W-1] = 1;

  mint ans = 1;
  for( int y=H-1; y>=0; y--){
    for( int x=W-1; x>=0; x--){
      if (y==H-1 && x==W-1) continue;
      if ( map[y][x] == 'D' ) sum[y][x] = sum[y+1][x];
      else if ( map[y][x] == 'R' ) sum[y][x] = sum[y][x+1];
      else if ( map[y][x] == 'X' ) sum[y][x] = sum[y][x+1] + sum[y+1][x];
      else {
        sum[y][x] = sum[y+1][x];
      
        

  return ans;
}

int main(){
  cout << solve() << endl;
}
