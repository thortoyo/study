// 食べるものを選んだ場合、その中で最後に食べるのは必ず一番時間がかかるものになる。
// それを利用し、Aiをソートしておいて、ナップサックDPすると、
// DP[i][] が 0～i-1 までの食べ物を選んで食べた場合の最大値になっているはず。
//  例えば 0,1,5,i-1 を選ぶのがベストだったとしても、0,1,2,10,i-5 がベストだったとしても
//  結局は DP[i][] にそのベストの値が入っている。
// なので、DP[i][] + i+1～N-1 のどれか が i 以上が最後に食べるものだった場合のMAX
// それを i を振って全部みたら、答えが出てくる。

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll dp[3005][3005];

int main() {
  ll N, T;
  cin >> N >> T;
  vector<pair<int,int> > AB(N);
  REP(i,N) {
    int a,b;
    cin >> a >> b;
    AB[i] = make_pair(a,b);
  }
  sort( AB.begin(), AB.end() ) ;
//  REP(i,N) cout << AB[i].first << " " << AB[i].second << endl;
  REP(i,N) {
    REP( ti, T ) {
      if ( ti >= AB[i].first) dp[i+1][ti] = max(dp[i][ti-AB[i].first] + AB[i].second, dp[i][ti] );
      else dp[i+1][ti] = dp[i][ti];
    }
  }
  ll ans = 0;
  REPI(i,0,N-1) {
    REPI(j,i+1,N) {
      ans = max( ans, dp[i+1][T-1] + AB[j].second );
    }
  }
//  REP(i,T) {
//    REP(j,N+1) {
//      printf("%3d ",dp[j][i]);
//    }
//    cout << endl;
//  }

  cout << ans << endl;
}
