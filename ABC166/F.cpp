#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  ll a,b,c;
  cin >> N >> a >> b >> c;
  vector<string> ans;
  int ng = 0;
  REP(i,N) {
    string s;
    cin >> s;
    if ( s == "AB" ) {
      if (a == b && a == 0) {
        ng = 1;
        break;
      }
      if (a>b) {
        a--; b++;
        ans.push_back("B");
      } else {
        a++; b--;
        ans.push_back("A");
      }
    } else if ( s == "BC" ) {
      if (b == c && b == 0) {
        ng = 1;
        break;
      }
      if (b>c) {
        b--; c++;
        ans.push_back("C");
      } else {
        b++; c--;
        ans.push_back("B");
      }
    } else {
      if (a == c && a ==0) {
        ng = 1;
        break;
      }
      if (a>c) {
        a--; c++;
        ans.push_back("C");
      } else {
        a++; c--;
        ans.push_back("A");
      }
    }
//    cout << a << " " << b << " " << c << endl;
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
