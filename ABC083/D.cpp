#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  int slen = S.length();
  int ans = slen;
  REP(i,slen-1) {
    if (S[i] != S[i+1]) {
      ans = min( ans, max(slen-i-1, i+1) );
    }
  }
 cout << ans << endl;
}

