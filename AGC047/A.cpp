#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// m[i][j] : 2��i�񊄂�؂�A5��j�񊄂�؂�鐔
int m[20][20];

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  REP(i,N) {
    // * 10^9 ���āA�S�������Ƃ���
    double a;
    cin >> a;
    ll b = ((a * (double)1000000000) + 0.5);
//    cout << " " << a << "  -> " << b;
    int n2= 0, n5 = 0;
    // �f�������������Ƃ���2�̌W�������߂�
    while ( b % 2 == 0 ) {
      n2++;
      b /= 2;
    }
    // �f�������������Ƃ���5�̌W�������߂�
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


