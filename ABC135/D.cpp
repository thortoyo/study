#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef int64_t ll ;
const ll MOD = 1000000007;

ll dp[100010][13];

int main() {
  string S;

  cin >> S;

  dp[0][0] = 1;

  // dp[i][j]: i文字目までの数値で、mod13が j である数値の総数
  for ( int i=0; i<S.length(); ++i ) {
    for ( int j=0; j<13; ++j ) {
      // "?"の場合は、その桁の数値が 0-9 全ての場合で調べる
      // それ以外の数値の場合は、その数値の場合のみ調べる
      for ( int n=0; n<10; ++n ) {
        if ( (S[i] != '?') && (S[i] != (n + '0')) ) continue;
        // AB という文字列だとして、A mod 13 が既知の場合に
        // i を一つ増やした場合（数値として扱う桁を右に一つ増やした場合）の mod13 は
        // (A * 10 + B) mod 13 で計算できる。
        // A mod 13 = Y とすると、
        // ((A mod 13) * (10 mod 13) + (B mod 13)) mod 13 = (Y * 10 + B) mod 13
        // となる。（B は 0 ～ 10 なので、13は超えない）
        dp[i+1][(j * 10 + n) % 13] += dp[i][j];
//        dp[i+1][(j * 10 + n) % 13] %= MOD;
      }
//      dp[i+1][j] = dp[i+1][j] % MOD;
    }
    REP(j,13)  dp[i+1][j] %= MOD;
  }

  cout << (dp[S.length()][5]) << endl;
  
}
