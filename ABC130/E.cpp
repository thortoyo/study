#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

typedef long long ll ;

const ll MOD = 1000000007;

ll dp[2100][2100];
ll sum[2100][2100];

int main() {

  int N,M;
  cin >> N >> M;
  vector< int > S(N+3),T(M+3);
  REP(i,N) cin >> S[i];
  REP(i,M) cin >> T[i];

  dp[0][0] = 1;
  sum[0][0] = 1;

  // dp[i][j] : S[i-1],T[j-1]�ŏI��镔��������
  //            i=0,j=0 �� �󕶎� �ɏ[�Ă�
  // sum[i][j] : dp[i][j]�ʒu�܂ł�2�����ݐϘa
  for(int i=0; i<N+1; ++i) {
    for(int j=0; j<M+1; ++j) {
      if ( i!=0 && j!=0 ) {
        if (S[i-1] == T[j-1]) dp[i][j] = sum[i-1][j-1];

        sum[i][j] = (sum[i-1][j] + sum[i][j-1]) % MOD;
        sum[i][j] = (sum[i][j] + dp[i][j]) % MOD;
        sum[i][j] -= sum[i-1][j-1];
        if ( sum[i][j] < 0 ) {
          sum[i][j] += MOD;
        }
      } else {
        sum[i][j] = 1;
      }
    }
  }
  cout << sum[N][M] << endl;

}
