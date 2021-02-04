#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for(int i=1; i<=N; i++) {
    int a = i;
    bool flg = true;
    REP(j,5) {
      if ( a % 10 == 7 ) {
        flg = false;
        break;
      }
      a /= 10;
    }
    a = i;
    if (flg) {
      REP(j,6) {
        if ( a % 8 == 7 ) {
          flg = false;
          break;
        }
        a /= 8;
      }
    }
    if (flg) {
//      cout << i << endl;
      ans++;
    }
  }
  cout << ans << endl;
}
