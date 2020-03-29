#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// ソートして端から順に処理していく。
// 左端を対処する場合には、その端の位置+D に爆弾を置くのが最適。それより左の位置に
// おいてもいいことはないし、それより右の位置に置くと、左端に当たらなくなる。
// 置く個数は、左端モンスターの倒す回数分。
// 置いた爆弾の位置と個数を管理しておいて、左端から順にモンスターを見ていく。
// 爆弾の範囲内で、その個数で倒れるなら、何もする必要なし。
// 爆弾の範囲内で、その個数で倒れないなら、+D 位置に倒れる個数の爆弾を置く。
// 爆弾の範囲外なら、爆弾の情報を削除し、+D 位置に倒れる個数の爆弾を置く。
// 爆弾は queue で管理する？
// 	D = 2
// 	0 1 2 3 4 5 6 7 8
// 	H 
// 	----B----
// 
// 全モンスターのループが O(N) で、その中で毎回爆弾のキューを全部回しているので
// 最悪 O(N^2) になっているっぽい。
// 体力が0以下になったら、キューの探索を止めたら？
//  → TLE
//     多少減るんだろうけど、(2*10^5)^2 から多少減って1/10とか1/100になっても、
//     まだ間に合わないってことらしい。
// ちゃんと、ダメージを尺取りしないとダメか・・・
// 爆弾を置いたら、その個数をトータル個数に加算。
// 位置が爆弾範囲を超えてたら、その超えた爆弾の個数をトータルから引く。

int main() {
  ll N,D,A;
  cin >> N >> D >> A;
  vector< pair<ll,ll> > mon(N);
  REP(i,N) {
    cin >> mon[i].first >> mon[i].second;
    mon[i].second = (mon[i].second+A-1) / A;
  }
  sort( mon.begin(), mon.end() );
  deque< pair<ll,ll> > q;
  ll ans = 0;
  ll total = 0;
  REP(i,N) {
    while ( !q.empty() ) {
      auto nq = q.front();
      if ( nq.first < mon[i].first ) {
        total -= nq.second;
        q.pop_front();
      } else {
        break;
      }
    }
    mon[i].second -= total;
    if ( mon[i].second > 0 ) {
      q.emplace_back( mon[i].first + 2 * D, mon[i].second );
      ans += mon[i].second;
      total += mon[i].second;
    }
  }
  cout << ans << endl;
}
