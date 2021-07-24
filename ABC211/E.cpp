#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

#define getmasu(i) s[(i)/N+1][(i)%N+1]

ll d[100];
ll c[100];
int dx = { 1,-1, 0, 0};
int dy = { 0, 0, 1,-1};

ll solve() {
  int N,K;
  cin >> N;
  cin >> K;
  string s[10];
  s[0] = "##########";
  REP(y,N) {
    cin >> s[y+1];
    s[y+1] = '#' + s[y+1] + '#';
  }
  s[N] = "##########";
  REP(i, (N+1)*(N+1)){
    if ( getmasu(i) == '#' ) continue;
    queue<int> q;
    q.push(i);
    while( !q.empty() ) {
      int v = q.front(); q.pop();
      if ( getmasu(i+8) == '#' ) continue;
  }
  return c[N-1].val();
}

int main(){
  cout << solve() << endl;
}
