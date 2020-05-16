#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  ll a,b,c;
  cin >> N >> a >> b >> c;
  vector<string> ans, s(N+1);
  int ng = 0;
  REP(i,N) cin >> s[i];
  s[N] = "ZZ";

  REP(i,N) {
    if ( s[i] == "AB" ) {
      if (a == b) {
        if (a == 0) {
          ng = 1;
          break;
        } else {
          if ( (s[i+1][0] == 'A') || (s[i+1][1] == 'A')) {
            a++; b--;
            ans.push_back("A");
          } else {
            a--; b++;
            ans.push_back("B");
          }
        }
      } else if (a>b) {
        a--; b++;
        ans.push_back("B");
      } else {
        a++; b--;
        ans.push_back("A");
      }
    } else if ( s[i] == "BC" ) {
      if (b == c) {
        if (b == 0) {
          ng = 1;
          break;
        } else {
          if ( (s[i+1][0] == 'B') || (s[i+1][1] == 'B')) {
            b++; c--;
            ans.push_back("B");
          } else {
            b--; c++;
            ans.push_back("C");
          }
        }
      } else if (b>c) {
        b--; c++;
        ans.push_back("C");
      } else {
        b++; c--;
        ans.push_back("B");
      }
    } else {
      if (a == c) {
        if (a == 0) {
          ng = 1;
          break;
        } else {
          if ( (s[i+1][0] == 'A') || (s[i+1][1] == 'A')) {
            a++; c--;
            ans.push_back("A");
          } else {
            a--; c++;
            ans.push_back("C");
          }
        }
      } else if (a>c) {
        a--; c++;
        ans.push_back("C");
      } else {
        a++; c--;
        ans.push_back("A");
      }
    }
//    cout << a << " " << b << " " << c << endl;
//    cout << s[i] << endl;
//    for ( auto sv : ans ) cout << sv << " "; cout << endl;
  }
  if ( ng == 1 ) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for ( auto sv : ans ) {
      cout << sv << endl;
    }
  }
}
