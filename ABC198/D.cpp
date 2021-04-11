#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll tbl[256];
bool used[10];
vector<char> moji, nzmoji;
string s1,s2,s3;
ll n1,n2,n3;

bool DFS(int rem){
  if (rem == 0) {
    n1 = n2 = n3 = 0;
//    cout << tbl['a'] << " " <<  tbl['b'] << " " <<  tbl['c'] << endl;
    REP(i,s1.length()) {
      n1 *= 10;
      n1 += tbl[ (int)s1[i] ];
    }
    REP(i,s2.length()) {
      n2 *= 10;
      n2 += tbl[ (int)s2[i] ];
    }
    REP(i,s3.length()) {
      n3 *= 10;
      n3 += tbl[ (int)s3[i] ];
    }
    if ( n1+n2 == n3 ) {
//      for ( auto m : moji ) cout << m << " ";
//      cout << endl;
//      REP(i,26) cout << tbl['a'+i] << " ";
//      cout << endl;
      return true;
    }
    return false;
  }
  REP(i, 10) {
    if ( used[i] ) continue;
    if ( i == 0 ) {
      bool flg = false;
      for ( auto nz : nzmoji ) if (nz == moji[rem-1]) flg = true;
      if ( flg ) continue;
    }
    used[i] = true;
    tbl[ (int)moji[rem-1] ] = i;
    if ( DFS( rem-1 ) ) return true;
    used[i] = false;
  }
  return false;
}

ll solve() {
  cin >> s1 >> s2 >> s3;
  string s = s1+s2+s3;
//  cout << s << endl;
  REP(i,s.length()) {
    bool flg = false;
    for( auto m : moji ) {
      if ( m == s[i] ) flg = true;
    }
    if ( flg ) continue;
    if ( moji.size() == 10 ) return false;
    moji.emplace_back( s[i] );
  }
  nzmoji.push_back( s1[0] );
  nzmoji.push_back( s2[0] );
  nzmoji.push_back( s3[0] );
  return DFS( moji.size());
}

int main(){
  if ( solve() ) {
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
  } else {
    cout << "UNSOLVABLE " << endl;
  }
}
