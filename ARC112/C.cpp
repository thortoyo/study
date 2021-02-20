#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


int coin[100005];
int inv[100005];

int solve(int v){
  if (to[v].empty()) {
    coin[v] = -1;
    inv[v] = 1;
    
  } else {
    for( auto nv: to[v] ) {
      

int main() {
  int n;
  cin >> n;
  vector< vector<int> > to(n);
  REP(i,n-1) {
    int p;
    cin >> p; p--;
    to[p].push_back(i+1);
  }
  
  cout << solve(0) << endl;
}
