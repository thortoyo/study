#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll DP[3030][3030];

//A の部分集合 T、Tの部分集合U で数える
int main(){
  int N, S;
  cin >> N >> S;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];

  DP[0][0] = 1;
  REP(i,N) REP(j,S+1) {
    // Ai が T に選ばれない場合
    DP[i+1][j] += DP[i][j];
    // Ai が T には選ばれているけど、Uには選ばれてない場合
    DP[i+1][j] += DP[i][j];
    DP[i+1][j] %= MOD;
    // Ai が選ばれた場合
    if ( A[i] + j <= S ) 
      DP[i+1][j+A[i]] += DP[i][j];
    DP[i+1][j] %= MOD;
  }
  cout << DP[N][S] << endl;
}
