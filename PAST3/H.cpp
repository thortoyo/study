#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int dp[100005];
int dp2[100005];
int x[100005];
const int INF = 2000000000;

int main(){
  int N,L;
  cin >> N >> L;
  REP(i,N) {
    int tx;
    cin >> tx;
    x[tx] = 1;
  }
  int T1, T2, T3;
  cin >> T1 >> T2 >> T3;

  REP(i,L+1) dp[i] = INF;
  REP(i,L+1) dp2[i] = INF;
  
  dp[0] = 0;
  dp2[0] = 0;
  REP(i,L) {
    // çsìÆ1
    dp[i+1] = min(dp[i+1], dp[i] + ((x[i+1]) ? T1+T3 : T1));
    dp2[i+1] = min(dp2[i+1], dp[i+1]);
    // çsìÆ2
    dp[i+2] = min(dp[i+2], dp[i] + ((x[i+2]) ? T1+T2+T3 : T1+T2));
    dp2[i+2] = min(dp2[i+2], dp[i+2]);
    dp2[i+1] = min(dp2[i+1], dp[i] + T1/2 + T2/2);
    // çsìÆ3
    dp[i+4] = min(dp[i+4], dp[i] + ((x[i+4]) ? T1+3*T2+T3 : T1+3*T2));
    dp2[i+4] = min(dp2[i+4], dp[i+4]);
    dp2[i+1] = min(dp2[i+1], dp[i] + T1/2 + T2/2);
    dp2[i+2] = min(dp2[i+2], dp[i] + T1/2 + T2/2*3);
    dp2[i+3] = min(dp2[i+3], dp[i] + T1/2 + T2/2*5);
//    REP(j,L+1)  cout << dp[j] << " ";
//    cout << endl;
//    REP(j,L+1)  cout << dp2[j] << " ";
//    cout << endl;
//    cout << endl;
  }
  cout << dp2[L] << endl;

}

