#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,K,C;
  string S;
  cin >> N >> K >> C >> S;
  vector<int> ok;
  bool flg = false;
  int cr = 0;
  REP(i,N) {
    if( flg ) {
      cr--;
      if (cr==0) flg = false;
    } else {
      if (S[i] == "o") {
        ok.push_back(i);
        if (C!=0) {
          flg = true;
          cr = C;
        }
      }
    }
  }

