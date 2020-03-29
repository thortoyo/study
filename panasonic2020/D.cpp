#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int N;
vector< string > sv;

void f( string a, int len, int m) {
//  cout << a << " " << len << " " << m << endl;
  REP(i,m+1) {
    string rs = a;
    rs += ('a' + i);
    if (len+1 < N ) {
      f(rs, len+1, max(m,i+1));
    } else {
      sv.push_back(rs);
    }
  }
  return;
}

int main(){
  cin >> N;
  string s;
  s = "";
  f( s, 0, 0);
  sort(sv.begin(), sv.end());
  for ( auto a : sv ) 
    cout << a << endl;
}

  
