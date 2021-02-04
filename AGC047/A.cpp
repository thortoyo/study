#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// m[i][j] : 2‚Åi‰ñŠ„‚èØ‚êA5‚Åj‰ñŠ„‚èØ‚ê‚é”
int m[20][20];

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  REP(i,N) {
    // * 10^9 ‚µ‚ÄA‘S•”®”‚Æ‚·‚é
    double a;
    cin >> a;
    ll b = ((a * (double)1000000000) + 0.5);
//    cout << " " << a << "  -> " << b;
    int n2= 0, n5 = 0;
    // ‘fˆö”•ª‰ð‚µ‚½‚Æ‚«‚Ì2‚ÌŒW”‚ð‹‚ß‚é
    while ( b % 2 == 0 ) {
      n2++;
      b /= 2;
    }
    // ‘fˆö”•ª‰ð‚µ‚½‚Æ‚«‚Ì5‚ÌŒW”‚ð‹‚ß‚é
    while ( b % 5 == 0 ) {
      n5++;
      b /= 5;
    }
    n2 = min(n2, 18);
    n5 = min(n5, 18);
//    cout << " " << n2 << " " << n5 << endl;
    for ( int i=18-n2; i < 19; i++ ) {
      for ( int j=18-n5; j < 19; j++ ) {
        ans += m[i][j];
      }
    }
    m[n2][n5]++;
  }
  cout << ans << endl;

}


