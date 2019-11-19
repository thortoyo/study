// 最後に食べるのを k としてみる。
// それ以外のものから選んでDPしてMAXを出して + Bi したら、i選択時のMAXが出る。
// その処理を k を全部振ると O(N^2T) になって間に合わない。
//
// 通常のDPでは、順番に1個ずつ、食べる、食べない、それぞれの場合でMAX値を
// 更新していく。なので i 番目まで処理が進んだ場合は、i までのものの内で最大値、ができている。
// これを利用すると、k よりも手前側の物を使ってのMAXがすでに求まっていることになる。
// なので、残りは k よりも向こう側の物だけを使ったMAX値が分かればいい。
// これは i を大きい順にDPを更新していけばOK。
// 
// それができれば、昇順DP[k][t1] と 降順DP[k][t2] の合計で、k 以外を使った場合のMAXが分かる。
// t1 と t2 は、t1 + t2 = T-1 となればいいので、時間を振って全部計算して最大値を見ればいい。
// O(NT) で分かる。

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll dp1[3005][3005];
ll dp2[3005][3005];

int main() {
  ll N, T;
  cin >> N >> T;
  vector<int> A(N), B(N);
  REP(i,N) {
    cin >> A[i] >> B[i];
  }
  REP(i,N) {
    int k = N-i-1;
    REP( ti, T ) {
      if ( ti >= A[i]) dp1[i+1][ti] = max(dp1[i][ti-A[i]] + B[i], dp1[i][ti] );
      else dp1[i+1][ti] = dp1[i][ti];
      if ( k > 0 ) {
        if ( ti >= A[k]) dp2[k-1][ti] = max(dp2[k][ti-A[k]] + B[k], dp2[k][ti] );
        else dp2[k-1][ti] = dp2[k][ti];
      }
    }
  }
  ll ans = 0;
  REP(i,N) {
    REP(j,T-1) {
      ans = max( ans, dp1[i][j] + dp2[i][T-1-j] + B[i] );
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
