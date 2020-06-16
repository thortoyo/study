#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector< int > ans(N,0);
  REP(i,N-1) {
    int c,s,f;
    cin >> c >> s >> f;
    REP(j,i+1) {
      if (ans[j] > s ) {
        if (ans[j] % f == 0)
          ans[j] += c;
        else
          ans[j] += f - ans[j] % f + c;
      } else {
        ans[j] = s + c;
      }
    }
//    cout << "--- " << i << endl;
//    REP(i,N)  cout << ans[i] << endl;
  }
  REP(i,N) {
    cout << ans[i] << endl;
  }
}

