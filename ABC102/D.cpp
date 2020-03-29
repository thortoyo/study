#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector< ll > A(N+1);
  A[0] = 0;
  REP(i,N) {
    ll a;
    cin >> a;
    A[i+1] = A[i] + a;
  }

//REP(i,N+1) cout << A[i] << " ";
//cout << endl;

  ll ans = 1000000000000000;
  // 探索開始位置は全部左端によせた場合
  //  探索時の判定条件を簡便にするために、C,E開始位置はB,D開始位置と同じにしている。
  //  こうすることで、最初の P と Q の比較で必ず Q の方が大きくなる。
  int st_c = 1;
  int st_d = 3;
  int st_e = 3;
  // D開始位置を振る
  for ( ; st_d < N; st_d++ ) {
    // C 開始位置を尺取り
    for ( ; st_c < st_d; st_c++ ) {
      if ( st_c+1 == st_d ) break;
      ll P0 = A[st_c-1] - A[0];
      ll Q0 = A[st_d-1] - A[st_c-1];
      ll P1 = A[st_c] - A[0];
      ll Q1 = A[st_d-1] - A[st_c];
      if ( abs(P0-Q0) < abs(P1-Q1) ) break;
    }
    // E 開始位置を尺取り
    for ( ; st_e < N+1; st_e++ ) {
      if ( st_e+1 == N+1 ) break;
      ll S0 = A[st_e-1] - A[st_d-1];
      ll T0 = A[N] - A[st_e-1];
      ll S1 = A[st_e] - A[st_d-1];
      ll T1 = A[N] - A[st_e];
      if ( abs(S0-T0) < abs(S1-T1) ) break;
    }
    ll P = A[st_c-1] - A[0];
    ll Q = A[st_d-1] - A[st_c-1];
    ll R = A[st_e-1] - A[st_d-1];
    ll S = A[N] - A[st_e-1];
    ll dif = abs( max(P, max(Q,max(R,S))) - min(P, min(Q,min(R,S))));
    ans = min( ans, dif );
//    cout << P << " " << Q <<  " " << R <<  " " << S << " : " << dif << endl;
  }
  
  cout << ans << endl;
}
