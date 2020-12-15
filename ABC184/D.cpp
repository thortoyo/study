#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

double dp[105][105][105];

int main(){
  ll A,B,C;
  cin >> A >> B >> C;
  
  for (int i=99; i>=A; i-- ) 
    for (int j=99; j>=B; j-- ) 
      for (int k=99; k>=C; k-- ) {
        dp[i][j][k] = ((double)i / (double)(i+j+k)) * dp[i+1][j][k] +
          ((double)j / (double)(i+j+k)) * dp[i][j+1][k] +
          ((double)k / (double)(i+j+k)) * dp[i][j][k+1] + 1;
      }
  printf("%.9f", dp[A][B][C]);
}
