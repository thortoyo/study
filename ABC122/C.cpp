#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> a(N,0);
  for( int i=1; i<N; ++i ) {
    a[i] = a[i-1];
    if ((S[i-1] == 'A') && (S[i] == 'C')) {
      a[i]++;
    }
  }
//  REP(i,N) cout << a[i] << " "; cout << endl;

  REP(i,Q) {
    int l,r;
    cin >> l >> r;
    l--; r--;
    cout << a[r]-a[l] << endl;
  }
}


