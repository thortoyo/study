#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// m[i][j] : 2でi回割り切れ、5でj回割り切れる数
int m[20][20];

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  REP(i,N) {
    // * 10^9 して、全部整数とする
    double a;
    cin >> a;
    ll b = ((a * (double)1000000000) + 0.5);
//    cout << " " << a << "  -> " << b;
    int n2= 0, n5 = 0;
    // 素因数分解したときの2の係数を求める
    while ( b % 2 == 0 ) {
      n2++;
      b /= 2;
    }
    // 素因数分解したときの5の係数を求める
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


