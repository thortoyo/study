#include <bits/stdc++.h>
//#include <chrono>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

//#define DMY_IN


int main() {
  ll N, M;
  vector< pair<ll,ll> > ABC;

//  std::chrono::system_clock::time_point  start, end; // 型は auto で可
//  start = std::chrono::system_clock::now(); // 計測開始時間

#ifdef DMY_IN
#else
  cin >> N >> M;
  REP(i,N) {
    ll ain;
    cin >> ain;
    ABC.emplace_back( ain, 1 ) ;
  }
  REP(i,M) {
    ll bi, ci;
    cin >> bi >> ci;
    ABC.emplace_back( ci, bi ) ;
  }
#endif

  sort( ABC.begin(), ABC.end(), greater< pair<ll,ll> >() );

//  REP(i,N+M)
//    cout << ABC[i].first << " " << ABC[i].second << endl;

  ll ans = 0;
  ll idx = 0;
  ll cnt = 0;
  REP(i,N) {
    ans += ABC[idx].first * ABC[idx].second;
    cnt += ABC[idx].second;
    if ( cnt >= N ) {
      ans -= (cnt-N) * ABC[idx].first;
      break;
    }
    idx++;
  }

  cout << ans << endl;
  

//  end = std::chrono::system_clock::now();  // 計測終了時間
//  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
//  std::cout << elapsed << " ms" << std::endl;
  
}


