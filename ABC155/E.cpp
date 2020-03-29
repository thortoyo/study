#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll dp[1000005][2];

int main() {
  string S;
  cin >> S;
  int slen = S.length();
  dp[slen][1] = 10000000;
  for ( int i=slen-1; i>=0; --i) {
    ll n = S[i] - '0';
    // iŒ…–Ú‚Í©•ª‚ªo‚·ê‡
    dp[i][0] = min(dp[i+1][0]+n, dp[i+1][1]+n+1);
    // iŒ…–Ú‚Í©•ª‚ªo‚³‚¸‚¨’Ş‚è‚ğ‚à‚ç‚¤ê‡
    dp[i][1] = min(dp[i+1][0]+((10-n)%10), dp[i+1][1]+9-n + ((S[i+1]=='0')?1:0));
  }
  ll ans = min(dp[0][0], dp[0][1]+1);
  cout << ans << endl;

//  REP(i,3) cout << " " << dp[i][0] ;
//  cout << endl;
//  REP(i,3) cout << " " << dp[i][1];
//  cout << endl;
}
