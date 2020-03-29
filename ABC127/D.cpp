#include <bits/stdc++.h>
//#include <chrono>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

//#define DMY_IN


int main() {
  ll N, M;
  vector< pair<ll,ll> > ABC;

//  std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
//  start = std::chrono::system_clock::now(); // �v���J�n����

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
  

//  end = std::chrono::system_clock::now();  // �v���I������
//  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
//  std::cout << elapsed << " ms" << std::endl;
  
}


