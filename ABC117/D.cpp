// https://atcoder.jp/contests/abc117/tasks/abc117_d
// 問題文
// N 個の非負整数 A1,A2,...,AN および非負整数 K が与えられます。
// 0 以上 K 以下の整数 X に対して、f(X)=(X XOR A1) + (X XOR A2) + ... + (X XOR AN) とします。
// ここで、非負整数 a,b に対して a XOR b は a と b のビットごとの排他的論理和を表します。
// f の最大値を求めてください。
// 制約
// 入力は全て整数である
// 1 ? N ? 10^5
// 0 ? K ? 10^12
// 0 ? Ai ? 10^12
//
// 入力
// 入力は以下の形式で標準入力から与えられる。
// N K
// A1 A2 ... AN
//
// 出力
// f の最大値を出力せよ。
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()


vector< vector<ll> > dp(51, vector<ll>(2,-1));

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  
  REP(i,N) cin >> A[i];

  dp[50][0] = 0;
  dp[50][1] = -1;
  for( int b=50-1; b>=0; --b ) {
    ll mask = 1LL << b;
    ll cnt1 = 0;
    REP(i,N) {
      if ( A[i] & mask ) cnt1++;
    }

    // Xi として 0 or 1 を選んだ時のスコア
    ll score0 = cnt1 * mask;
    ll score1 = (N-cnt1) * mask;
    
    // dp[i][0] : i bit目までの合計値、上位bitはKと一致
    // dp[i][1] : i bit目までの合計値、上位bitはKよりも小さい

    // dp[i+1][0] <= dp[i][0] : Xi == Ki なので、Ki を見てscore0/1を加算
    dp[b][0] = dp[b+1][0] + ((K & mask) ? score1 : score0);
    
    // dp[i+1][1] <= dp[i][0] : これは Ki==1 の場合のみ発生。Xiは自動的に 0 と決まる
    //            <= dp[i][1] : Xi は 0/1 どちらでもいいので、scoreの大きい方
    //  但し、上位Bitがずっと K と一致したものしかなかった場合（KのMSBがずっと0だった場合など）
    //  dp[b+1][1] から加算するという遷移は存在しない
    if ( dp[b+1][1] != -1 )
      dp[b][1] = dp[b+1][1] + max( score0, score1 );
    if ( K & mask )
      dp[b][1] = max( dp[b][1], dp[b+1][0] + score0 );
  }
//  REP(i,N+1)
//    cout << dp[i][0] << " ";
//  cout << endl;
//  REP(i,N+1)
//    cout << dp[i][1] << " ";
//  cout << endl;

  cout << max(dp[0][1], dp[0][0]) << endl;

}

