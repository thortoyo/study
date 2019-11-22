#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,A,B,C;
  cin >> N >> A >> B >> C;
  vector<int> L(N,0);
  REP(i,N) cin >> L[i];

  int la,lb,lc;
  int mi = 1 << 30;
  for(ll i=0 ;i<(1<<(N*2)); ++i ) {
    int mp = 0;
    la = lb = lc = 0;
    REP(j,N) {
      int t = (i >> (j*2)) & 3;
      if ( t == 1 ) {
        if ( la != 0 ) mp += 10;
        la += L[j];
      } else if ( t == 2 ) {
        if ( lb != 0 ) mp += 10;
        lb += L[j];
      } else if ( t == 3 ) {
        if ( lc != 0 ) mp += 10;
        lc += L[j];
      }
    }
    if ( (la == 0) || (lb == 0) || (lc == 0) ) continue;
    mp += abs(A-la)+abs(B-lb)+abs(C-lc);
    mi = min(mi, mp);
  }
  cout << mi << endl;

  return 0;
}
