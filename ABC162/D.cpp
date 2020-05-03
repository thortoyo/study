#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main(){
  int N;
  string S;
  cin >> N >> S;

  vector<int> kr(N,0), kg(N,0), kb(N,0);
  for (int i=N-1; i>=0; --i ) {
    if ( S[i] == 'R' ) kr[i] = 1;
    else if ( S[i] == 'G' ) kg[i] = 1;
    else kb[i] = 1;
  }
  for (int i=N-2; i>=0; --i ) {
    kr[i] += kr[i+1];
    kg[i] += kg[i+1];
    kb[i] += kb[i+1];
  }
  ll ans = 0;
  REP(i,N-3) {
    for(int j=i+1; j<N-1; ++j ) {
      if ( S[i] == S[j] ) continue;
      if ( ((S[i] == 'R') && (S[j] == 'G')) || ((S[i] == 'G') && (S[j] == 'R')) ) {
        ans += kb[j+1];
        if ( ((j + j - i) < N) and (S[j + j - i] == 'B') ) ans--;
      } else if ( ((S[i] == 'B') && (S[j] == 'G')) || ((S[i] == 'G') && (S[j] == 'B')) ) {
        ans += kr[j+1];
        if ( ((j + j - i) < N) and (S[j + j - i] == 'R') ) ans--;
      } else {
        ans += kg[j+1];
        if ( ((j + j - i) < N) and (S[j + j - i] == 'G') ) ans--;
      }
    }
  }
  cout << ans << endl;
}
