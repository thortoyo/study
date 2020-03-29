#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

// DP[y][x] : �ォ��y�Ԗڂ̍s�ŁA������ x �Ԗڂ̏c�_�ɁA1����X�^�[�g���Ă��ǂ蒅���g�ݍ��킹�̐�
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
      // �܂�����
      dp[y][x] += (dp[y-1][x] * f[ max(x-1,0) ] * f[ max(W-x-2,0) ]) % MOD;
      // ������
      if (x > 0)
        dp[y][x] += (dp[y-1][x-1] * f[ max(x-2,0) ] * f[ max(W-x-2,0) ]) % MOD;
      // �E����
      if (x < W-1)
        dp[y][x] += (dp[y-1][x+1] * f[ max(x-1,0) ] * f[ max(W-x-3,0) ]) % MOD;
    }
  cout << (dp[H][K-1] % MOD) << endl;
}
