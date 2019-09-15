#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,K,Q;
  cin >> N >> K >> Q;
  vector<ll> AC(N, K-Q );
  REP(i,Q) {
    int ain;
    cin >> ain;
    ain--;
    AC[ain]++;
  }
  REP(i,N) {
    if ( AC[i] > 0 ) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
