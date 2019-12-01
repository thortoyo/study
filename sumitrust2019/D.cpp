#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  string S;
  cin >> N >> S;
  set<int> code, up;
  int a = stoi(S.substr(0,3));
  code.insert(a);
  up.insert(stoi(S.substr(0,2)));
  int sn = S[2] - '0';
  vector<int> add;
  for(auto u:up) {
    add.push_back( (u*10+sn)%100 );
    add.push_back(((u/10)*10+sn)%100 );
  }
  for(auto ad:add) {
    up.insert(ad);
  }
//    cout << " --- " << S[2] << endl;
//    for(auto u:up) {cout << u << " ";} cout << endl;
  for( int i=3;i<N;i++) {
    int sn = S[i] - '0';
    for(auto u:up) {
      code.insert( u*10 + sn );
    }
    vector<int> add;
    for(auto u:up) {
      add.push_back( (u*10+sn)%100 );
      add.push_back(((u/10)*10+sn)%100 );
    }
    for(auto ad:add) {
      up.insert(ad);
    }
//    cout << " --- " << S[i] << endl;
//    for(auto u:up) {cout << u << " ";} cout << endl;
  }
  cout << code.size() << endl;
//  for(auto c:code) cout << c << endl;
  
}

