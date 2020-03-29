#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,P;
  string S;
  cin >> N >> P >> S;

  map<int, int> M;
  ll ans = 0;
  
  if ((P==5) || (P==2)) {
    for (int i=0;i<N;++i) {
      if ( (S[i]-'0') % P == 0 ) ans += i+1;
    }
  } else {
    int pre = 0;
    int ten = 1;
    M[0] = 1;
    for (int i=N-1; i>=0; --i) {
      int mod = ((S[i]-'0') * ten) % P;
      mod = (mod + pre) % P;
      ans += M[mod];
      M[mod]++;
      pre = mod % P;
      ten = ten * 10 % P;
    }
//    for( auto m: M )
//      cout << m.first << " " << m.second << endl;
  }
  cout << ans << endl;
}

  
