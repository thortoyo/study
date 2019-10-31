#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

double dp[601], dp2[601];

int main() {
  int N, M;
  cin >> N >> M;
  vector< vector<int> > to(N), ot(N);	// 接続先、接続元
  vector< int > o(N,0);	// 出自数
  vector< double > p(N,0);	// 到着確率

  REP(i,M) {
    int src, dst;
    cin >> src >> dst;
    src--; dst--;
    to[src].push_back(dst);
    ot[dst].push_back(src);
    o[src]++;
  }

  // 初期状態での期待値生成
  for (int i=N-2; i>=0; --i ) {
    for ( auto r: to[i] ) {
      dp[i] += dp[r];
    }
    dp[i] /= o[i];
    dp[i] += 1;
  }

  // 初期状態での到着確率生成
  p[0] = 1;
  for( int i=0; i<N; i++ ) {
    for ( auto r: to[i] ) {
      p[r] += p[i] / o[i];
    }
  }

//  REP(i,N)
//    cout << i << " : " << p[i] << " " << dp[i] << endl;

  double E = dp[0];
  REP(i,N) dp2[i] = dp[i];

  // 前から順に一番期待値に影響が大きい辺を削除して期待値再計算する
  for (int i=0; i<N-1; ++i ) {
    if (o[i] == 1) continue;	// 出自数が1なら削除できない
    vector< double > v;
    for ( auto r: to[i] ) v.push_back(dp[r]);
    sort(v.begin(), v.end());
    v.pop_back();		// 一番大きい期待値を除外
    // 消した辺の始点の期待値再計算
    dp2[i] = 0;
    for( auto x: v ) dp2[i] += x;
    dp2[i] /= (o[i]-1);
    dp2[i] += 1;
    // 現在位置より手前の期待値再計算
    for (int j=i-1; j>=0; --j) {
      dp2[j] = 0;
      for ( auto r: to[j] ) {
        dp2[j] += dp2[r];
      }
      dp2[j] /= o[j];
      dp2[j] += 1;
    }
    E = min( E, dp2[0] );
    
    REP(k,N) dp2[k] = dp[k];
  }
  cout << fixed << setprecision(10) << E << endl;
}
