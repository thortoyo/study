#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans=0;
  REP(a2,10) {
    REP(a1,10) {
      REP(a0,10) {
        int fnd = 0;
        REP(i,N) {
          if(fnd==0) {
            if ( a2 == (S[i]-'0') ) fnd++;
          } else if(fnd==1) {
            if ( a1 == (S[i]-'0') ) fnd++;
          } else {
            if ( a0 == (S[i]-'0') ) {
              ans++;
              break;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;

}

