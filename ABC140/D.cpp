#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string ns(s);
  int first = 1;
  int ans = 0;
  int cnt = 0;
  char tgt = 'a';
  ns[0] = s[0];
  for(int i=1;i<n;i++) {
    if (s[i-1] != s[i] ) {
      if (tgt == 'a') {
        tgt = s[i];
      }
      if( cnt == 1 ) {
        cnt = 0;
        --k;
        if (k==0) break;
      }
      else {
        ns[i] = (tgt=='L') ? 'R' : 'L';
        cnt = 1;
      }
    } else {
      if(cnt == 1) {
        ns[i] = (tgt=='L') ? 'R' : 'L';
      }
    }
  }

  ns = "R" + ns + "L";
  for ( int i=1; i<=n; ++i) {
    if( ns[i] == 'L' ) {
      if ( ns[i-1] == 'L' ) ans++;
    } else {
      if ( ns[i+1] == 'R' ) ans++;
    }
  } 
  
//  cout << ns << endl;
  cout << ans << endl;

}
