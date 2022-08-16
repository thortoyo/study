#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

string solve() {
  string S;
  int k;
  cin >> S >> k;
  vector<string> SS;
  sort(S.begin(), S.end());
  SS.push_back(S);
  while ( next_permutation(S.begin(), S.end()) ){
    SS.push_back(S);
  }
  return SS[k-1];
}

int main(){
  cout << solve() << endl;
}


