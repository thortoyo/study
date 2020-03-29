// ゴールから逆算する。
// ゴールからすると、一番遠い距離に行くのが手数を少なくするためには最善。
// なので、ゴールからMの距離から順に到着できるところを探す。
// M 以内にスタート地点が来た場合、一手前に戻ってスタート地点から
// 2手で進む場合に1手目が一番小さい数字になる場合を探す？

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N,M;
  string S;
  cin >> N >> M >> S;
  int now = N;
  vector<int> r;
  
  if ( N <= M ) {
    cout << min(N,M) << endl;
    return 0;
  }

  while ( now-M > 0 ) {
    int jump = 0;
    for(jump=M; jump>0; --jump) {
      if ( S[now-jump] == '1' ) continue;
      r.emplace_back( jump );
      break;
    }
    if ( jump==0 ) {
      cout << "-1" << endl;
      return 0;
    }
    now -= jump;
  }
  if ( now-M == 0 ) {
    r.emplace_back( M );
  } else {
    int &pre = r.back();
    r.pop_back();
    now += pre;
    for(int jump=1; jump<=M; ++jump) {
      if ( S[jump] == '1' ) continue;
      if ( jump+M < now ) continue;
      r.emplace_back( now-jump );
      r.emplace_back( jump );
      break;
    }
  }
  reverse( r.begin(), r.end() );
  for (auto x: r ) cout << x << " ";
  cout << endl;
}
