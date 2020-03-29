#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

// DP[y][x] : 上からy番目の行で、左から x 番目の縦棒に、1からスタートしてたどり着く組み合わせの数
ll dp[102][9];

int main() {
  int H,W,K;
  cin >> H >> W >> K;
  ll f[10];
  f[0] = 1;
  f[1] = 2;
  for(int i=2;i<10;i++) f[i] = f[i-1] + f[i-2];

  dp[0][0] = 1;
  for(int y=1;y<H+1;++y)
    REP(x,W) {
      // まっすぐ
      dp[y][x] += (dp[y-1][x] * f[ max(x-1,0) ] * f[ max(W-x-2,0) ]) % MOD;
      // 左から
      if (x > 0)
        dp[y][x] += (dp[y-1][x-1] * f[ max(x-2,0) ] * f[ max(W-x-2,0) ]) % MOD;
      // 右から
      if (x < W-1)
        dp[y][x] += (dp[y-1][x+1] * f[ max(x-1,0) ] * f[ max(W-x-3,0) ]) % MOD;
    }
  cout << (dp[H][K-1] % MOD) << endl;
}
