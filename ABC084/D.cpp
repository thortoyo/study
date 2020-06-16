#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int prime[100005];
int p2[100005];

int main() {
  int Q;
  cin >> Q;
  REP(i, 100005) prime[i] = 1;
  prime[0] = 0;
  prime[1] = 0;
  for (int i=2; i*i<=100005; i++ ) {
    if ( prime[i] == 1 ) {
      for (int j=2; i*j<=100005; j++ ) {
        prime[i*j] = 0;
      }
    }
  }
//  REP(i, 100) cout << i << " : " << prime[i] << endl;
  for ( int i=3; i<100005; i+=2 ) {
    if ( prime[i] == 1 && prime[(i+1)/2] == 1 ) p2[i] = 1;
  }
  REP(i, 100005) p2[i+1] += p2[i];
//  REP(i, 100) cout << i << " : " << p2[i] << endl;
  REP(i,Q) {
    int l,r;
    cin >> l >> r;
    int ans = p2[r] - p2[l-1];
    cout << ans << endl;
  }
}

