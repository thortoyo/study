#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int m[201][201];
int use[201];
int usen[201];
int ans[2][201];
ll A[201];

void solve() {
  int N;
  cin >> N;
  REP(i,N) {
    cin >> A[i];
//    cout << A[i] << "---" << A[i]%200 << endl;
    REP(j,200) {
      if ( use[j] != 0 ) {
//        cout << "  " << j << " : " << (j+A[i])%200 << endl;
        if ( use[(j+A[i])%200] == 0 ) {
          REP(k,200) m[(j+A[i])%200][k] = m[j][k];
          usen[(j+A[i])%200] = use[j] + 1;
          m[(j+A[i])%200][i] = 1;
        } else {
          m[j][i] = 1;
          ans[0][200] = use[(j+A[i])%200];
          REP(k,200) ans[0][k] = m[(j+A[i])%200][k];
          ans[1][200] = use[j]+1;
          REP(k,200) ans[1][k] = m[j][k];
          return;
        }
        usen[j] = use[j];
      }
    }
    if ( usen[A[i]%200] == 0 ) {
      usen[A[i]%200] = 1;
      m[A[i]%200][i] = 1;
    } else {
      REP(k,201) ans[0][k] = m[A[i]%200][k];
      ans[0][200] = usen[A[i]%200];
      ans[1][200] = 1;
      ans[1][i] = 1;
      return;
    }
    REP(j,200) {
//      if ( usen[j] == 1 ) cout << j << " ";
      use[j] = usen[j];
    }
//    cout << endl;
  }
  return;
}

int main(){
  solve();
  if (ans[0][200] == 0 ) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << ans[0][200] << " ";
    REP(i, 200)  if ( ans[0][i] == 1 ) cout << (i+1) << " ";
    cout << endl;
    cout << ans[1][200] << " ";
    REP(i, 200)  if ( ans[1][i] == 1 ) cout << (i+1) << " ";
    cout << endl;
  }
}
