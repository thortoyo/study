#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll DP[3030][3030];

//A �̕����W�� T�AT�̕����W��U �Ő�����
int main(){
  int N, S;
  cin >> N >> S;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];

  DP[0][0] = 1;
  REP(i,N) REP(j,S+1) {
    // Ai �� T �ɑI�΂�Ȃ��ꍇ
    DP[i+1][j] += DP[i][j];
    // Ai �� T �ɂ͑I�΂�Ă��邯�ǁAU�ɂ͑I�΂�ĂȂ��ꍇ
    DP[i+1][j] += DP[i][j];
    DP[i+1][j] %= MOD;
    // Ai ���I�΂ꂽ�ꍇ
    if ( A[i] + j <= S ) 
      DP[i+1][j+A[i]] += DP[i][j];
    DP[i+1][j] %= MOD;
  }
  cout << DP[N][S] << endl;
}
