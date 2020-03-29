#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

int ma[10] = { 0,2,5,5,4,5,6,3,7,6 };

// dp[i] : i本使った時の最大値
string dp[10020];

void str_max( string& a, string& b ) {
  if ( a.size() < b.size() ) {
    a = b;
  } else if ( a.size() == b.size() ) {
    if ( b > a ) a = b;
  }
  return;
} 
int main() {
  int N, M;
  cin >> N >> M;
  vector< int > A(M);
  REP(i,M) {
    cin >> A[i];
  }
  // "-"を初期値とする。初期値の場合は、その本数になることがないことを示す。
  // はじめは不要かと思ってたけど、dp[0] = "" の状態と、存在しないは違う。
  // 存在しない場合はそのdp[i]を起点とすることができない。
  REP(i,N) dp[i] = "-";

  dp[0] = "";
  REP(i,N+1) {
    for ( auto x: A ) {
      // 存在しない場合は飛ばす
      if ( dp[i] == "-" ) continue;
      string b = dp[i] + (char)('0'+x);
      str_max( dp[i+ma[x]], b );
    }
  }
  
  cout << dp[N] << endl;
}
