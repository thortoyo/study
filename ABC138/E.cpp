#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > snext( 100005, vector<int>(26,0) );

int main() {
  string s,t;
  cin >> s >> t;

  int slen = s.length();
  int tlen = t.length();

  // インデックス作成
  for(int i=slen-1;i>=0; i--) {
    for (int j=0; j<26; ++j ){
      snext[i][j] = snext[i+1][j];
    }
    char c = s[i] - 'a';
    snext[i][c] = i+1;
  }

//  for(int i=0;i<slen+1;++i) {
//    cout << i << " : ";
//    for(int j=0;j<26;++j) {
//      cout << snext[i][j] << " ";
//    }
//    cout << endl;
//  }

  // t の各文字を検索
  int64_t ans = 0;
  int64_t spos = 0;
  for (int i=0; i<tlen; ++i ){
    char c = t[i] - 'a';
    int next = snext[spos][c];
    if ( next == 0 ) {
      ans += slen;
      next = snext[0][c];
      if ( next == 0 ) {
        cout << "-1" << endl;
        return 0;
      }
    }
    spos = next;
//    cout << spos << endl;
  }

  cout << ans+spos << endl;

}
