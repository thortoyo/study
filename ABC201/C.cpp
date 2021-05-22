#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll solve() {
  string s;
  cin >> s;
  int ans = 0;
  REP(i,10000) {
    int tgt = i;
    vector<int> n(11,0);
    REP(j,4) {
      n[tgt % 10]++;
      tgt /= 10;
    }
    bool flg = true;
    REP(j,10) {
      if ((s[j] == 'o') && (n[j] == 0)) flg = false;
      if ((s[j] == 'x') && (n[j] != 0)) flg = false;
    }
    if ( flg ) ans++;
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
