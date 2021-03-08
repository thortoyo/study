#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

double dp[112345];

double solve() {
  ll N;
  cin >> N;
  for( int i=1;i<N;i++) {
    double aa = 0.0;
    aa = dp[i-1] + ((double)N / (double)(N - i));
    dp[i] = aa;
  }
  return dp[N-1];
}

int main(){
  cout << fixed << setprecision(7) << solve() << endl;
}
