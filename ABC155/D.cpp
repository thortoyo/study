#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), AR(N);
  REP(i,N) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  reverse_copy(A.begin(), A.end(), AR.begin());

  ll l = (1LL << 62) * -1;
  ll r = 1LL << 62;
  while ( l+1 < r ) {
    ll mid = (l + r) / 2;
    ll lnum = 0;
//    cout << "l: " << l << " , r: " << r << " , mid: " << mid << endl;
    REP(i,N-1) {
      int min_n, max_n;
      bool neg;
      if (A[i] < 0) {
        min_n = N-1; max_n = i+1; neg = true;
      } else {
        min_n = i+1; max_n = N-1; neg = false;
      }
      if ( A[i] * A[min_n] > mid ) {
        // A[i]との積の最小値よりも小さい場合は、0 個
      } else if ( A[i] * A[max_n] <= mid ) {
        // A[i]との積の最大値よりも大きい場合は、N-i-1 個
        lnum += N-i-1;
//        cout << "  + " << mid << " " << i << " " << max_n << " : " << lnum << endl;
      } else {
        int l1 = min_n;
        int r1 = max_n;
//        cout << "  * " << l1 << " " << r1 << endl;
        while( neg ? (l1 > r1+1) : (l1+1 < r1) ) {
          int mid1 = (l1+r1)/2;
//          cout << "  l1: " << l1 << " , r1: " << r1 << " , mid1: " << mid1 << endl;
          if (A[mid1] * A[i] <= mid ) {
            l1 = mid1;
          } else {
            r1 = mid1;
          }
        }
        lnum += (neg ? N-l1 : l1-i);
      }
//      cout << " - lnum " << lnum << endl;
    }
    if (lnum < K) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << r << endl;
}

  


