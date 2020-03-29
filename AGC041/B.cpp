#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll M,N,V,P;
vector< ll > A;

bool judge( ll mid ) {
//  cout << " A[mid] " << A[mid] << endl;
  // A[mid]+M < A[P-1] なら何をやってもNG
  if ( A[mid] + M < A[P-1] ) return false;

  ll zan = (V-1) * M;
//  cout << " " << zan << endl;
  // A[mid]+M よりも大きいスコアが P-1 個以下ならOK
  //  A[mid+1]～A[N-1] は +M しても影響なし。
  zan -= (N-(mid+1)) * M;
//  cout << " " << zan << endl;
  //  大きい順に P-1 個目までは +M しても影響なし。
  zan -= (P-1) * M;
//  cout << " " << zan << endl;
  if ( zan <= 0 ) return true;
  // 残った A[P-1] ～ A[mid-1] までの区間で、A[mid] を超えないように足す
  for (int i=P-1; i<mid; i++) {
    zan -= (A[mid]+M-A[i]);
//    cout << " " << zan << endl;
    if ( zan <= 0 ) return true;
  }
  return false;		// それでも余ったらNG
}

int main() {
  cin >> N >> M >> V >> P;
  REP(i,N) {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end(), greater<ll>() );
  
  ll l = P-1;	// 大きい順にP個目までは、無条件でOK
  ll r = N;
  ll mid;
  while( l+1 < r ) {
    mid = (l+r)/2;
    if ( judge(mid) ) {
//      cout << mid << " OK" << endl;
      l = mid;
    } else {
//      cout << mid << " NG" << endl;
      r = mid;
    }
  }
  cout << (l+1) << endl;
}
