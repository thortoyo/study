#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

bool seen[2002];
ll T[100001];
ll K[100001];
ll tim[100001];
vector< vector< tuple<int,ll,ll> > > to(100001);

ll minc;
int goal;

  
void solve() {
  int N, M, X, Y;
  X--; Y--;
  cin >> N >> M >> X >> Y;
  REP(i,M) {
    int a,b; ll t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    to[a].emplace_back(b,t,k);
    to[b].emplace_back(a,t,k);
    
  }
  priorty_queue<pair<ll, int> > q;
  q.emplace(0,X);
  REP(j,N) seen[j] = false;
  while( !q.empty()) {
    auto v = q.last(); q.pop();
    for( auto nv : to[v] ) {
      
      tim[v] + K[v]
      if ( tim[nv] > 
    
  cout << minc << endl;
  }
}

int main(){
  solve();
}
