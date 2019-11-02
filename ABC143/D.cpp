#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N;
  cin >> N;
  vector< int > L(N);
  ll ans = 0;

  REP(i,N)  cin >> L[i];
  sort( L.begin(), L.end() ) ;

//  REP(i,N) cout << L[i] << " "; cout << endl;
  
  for (int i=0; i<N-2; ++i ) {
    for (int j=i+1; j<N-1; ++j ) {
      int ab = L[i] + L[j];
//      cout << L[i] << " " << L[j] << " : ab " << ab << " : ans " << ans << endl;
      // 全部対象外
      if ( L[j+1] >= ab ) continue;
      // 全部対象内
      if ( L[N-1] < ab ) {
        // 2 2 3 3
        // N=4, j=1, ab=4 2個 = 4 - 1 - 1
        ans += N-j-1;
//        cout << "  all ans += " <<  N-j-1 << endl;
        continue;
      }
      // 二部探索で、c < a + b の c になる位置を探す
      int l = j;
      int r = N-1;
      int mid;
      while( r-l>1 ) {
        mid = (r+l) / 2;
//        cout << "    2bu " << l << " " <<  mid << " " << r << endl;
        if ( L[mid] < ab ) {
          l = mid;
        } else {
          r = mid;
        }
      }
      // 2 2 3 3 4
      // N=5, j=1, ab=4 2個 =  3 - 1;
      ans += l - j;
//      cout << "  2bu ans += " <<  l - j << endl;
    }
  }
  cout << ans << endl;

}
