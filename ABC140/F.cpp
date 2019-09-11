#include <bits/stdc++.h>
//#include <chrono>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

//#define DMY_IN

int main() {
  int N;
#ifdef DMY_IN
  N = 18;
#else
  cin >> N;
#endif
  int smax = 1 << N;
  multiset<ll> S;
  vector<ll> SO;
  vector<ll> SO_add;

//  std::chrono::system_clock::time_point  start, end; // 型は auto で可
//  start = std::chrono::system_clock::now(); // 計測開始時間

  REP(i,smax) {
    ll sin;
#ifdef DMY_IN
    if ( i==0 ) {
      S.emplace(1000000000);
    } else if ( i < ((1<<17)) ) {
      S.emplace(1000000000 - 1);
    } else {
      S.emplace(i);
    }
#else
    cin >> sin;
    S.emplace(sin);
#endif
  }
  // 末尾が最大なので、まずはそれを生成済み配列に移す
  SO.emplace_back( *(S.rbegin()) );
  // erase() の引数に指定するには、リバースイテレータは使えず、普通のイテレータのみ
  // らしいので、end() からデクリメントして末尾を指定している
  multiset<ll>::const_iterator sit = S.end();
  sit--;	// 末尾 = 最大値の箇所
  S.erase(sit);

  sort( SO.begin(), SO.end(), greater<ll>() );

  for (int i=0; i<N; i++ ) {
//    for ( auto x: SO) cout << x << " ";
//    cout << endl;
//    cout << i << endl;
    
    for ( auto oya : SO ) {
      if ( S.empty() ) {
        cout << "No" << endl;
        return 0;
      }
      auto sit = S.lower_bound(oya);	// S[*] >= oya を満たす最小の要素を指す
      if ( sit == S.begin() ) {
        cout << "No" << endl; return 0;
      }
      sit--;
//      cout << "  o " << oya << " " <<  *sit << endl;
      SO_add.emplace_back( *sit );
      sit = S.erase(sit);
    }
    for( auto x: SO_add ) {
      SO.emplace_back( x );
    }
    sort( SO.begin(), SO.end(), greater<ll>() );
    SO_add.clear();
  }
  cout << "Yes" << endl;

//  end = std::chrono::system_clock::now();  // 計測終了時間
//  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
//  std::cout << elapsed << " ms" << std::endl;
  
}


