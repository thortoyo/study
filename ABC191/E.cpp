#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

bool seen[2002];
vector< vector<int> > to(2002);
vector< vector<ll> > tim(2002, vector<ll>(2002,0));

ll minc;
int goal;

void DFS(int v, ll d){
  for ( auto nv : to[v] ) {
    if ( nv == goal ) {
      minc = min(minc, d+ tim[v][nv]);
      return;
    }
    if ( seen[nv] ) continue;
    seen[nv] = true;
    ll nd = d + tim[v][nv];
    DFS(nv, nd);
  }
}

  
void solve() {
  int N, M;
  cin >> N >> M;
  REP(i,M) {
    int a,b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    if ( tim[a][b] != 0 ) tim[a][b] = min(tim[a][b], c);
    else tim[a][b] = c;
    to[a].push_back(b);
  }
  REP(i,N) {
    priorty_queue<pair<ll, int> > q;
    q.emplace(0,i);
    REP(j,N) seen[j] = false;
    goal = i;
    minc = 1000000000LL;
    DFS(i,0);
    if ( minc == 1000000000LL ) minc = -1;
    cout << minc << endl;
  }
}

int main(){
  solve();
}
