#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N,M;
  cin >> N >> M;
  vector< ll > A(N);
  vector< ll > AA(N,0);
  REP(i,N) cin >> A[i];
  
  sort(A.begin(), A.end());
  
  AA[0] = A[N-1];
  for(int i=1;i<N;i++) AA[i] = AA[i-1] + A[N-1-i];

  // N*Nのマスで考える。
  // 各行である数xを超える個数を数える。
  //  最初の行は二分探索でもとめて、その次の行からは尺取りで1個ずつ上に探索していく
  // その合計がMを超える最小のxを二分探索で求める。

  ll left = 1LL << 60;
  ll right = 0;
  ll mid = (left + right) / 2;
  ll xnum = 0;
  ll xtotal = 0;
  while( left - right > 1 ) {
    xnum = 0;
    xtotal = 0;
//    cout << right << " : " << mid << " : " << left << endl;
    REP(i,N) {
      ll x = max(mid - A[i], 0LL);
      auto it = lower_bound( A.begin(), A.end(), x );
      ll dist = distance( it, A.end());
      xnum += dist;
//      cout << "  " << xnum;
    }
//    cout << endl;
    if ( xnum >= M ) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2;
  }
  xnum = 0;
  xtotal = 0;
//  cout << right << " : " << mid << " : " << left << endl;
  REP(i,N) {
    ll x = max(right - A[i], 0LL);
    auto it = lower_bound( A.begin(), A.end(), x );
    ll dist = distance( it, A.end());
    xnum += dist;
    if (xnum>0) xtotal += (AA[dist-1] + A[i]*dist);
//    cout << "  " << xnum << " " << xtotal;
  }
//  cout << endl;

  cout << xtotal - (xnum-M)*right << endl;
}
