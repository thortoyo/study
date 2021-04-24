#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

vector< vector<int> > to(21);
int col[21];
ll ans = 1;
int N, M;

bool chk_ill(int v0, int v1, int v2){
  int flg[21];
  REP(i,21) flg[i] = 0;
  for( auto nv : to[v0] ) flg[nv]++;
  for( auto nv : to[v1] ) flg[nv]++;
  for( auto nv : to[v2] ) flg[nv]++;
  REP(i,21) {
    if ( flg[i] == 3 ) return true;
  }
  return false;
}


bool chk(int v, int prev){
  for( auto nv : to[v] ) {
    if ( col[nv] != 0 ) {
      for( auto nnv : to[nv] ) {
//        printf("   chk  %d -> %d -> %d  %d\n",v,nv,nnv,col[nv]);
        if ( (prev == nnv) && (col[nv] != 0)) {
          if ( chk_ill(v, nv, prev) ) ans = 0;
          return true;
        }
      }
    }
  }
  return false;
}

void DFS(int v){
//  printf("%d %d\n",v, ans);
  for( auto nv : to[v] ) {
    if ( col[nv] != 0 ) {
      continue;
    }
    if ( !chk(nv, v) )  ans *= 2;
//    printf(" -> %d %d\n",nv, ans);
    col[nv] = 1;
    DFS(nv);
  }
  return;
}

ll solve() {
  cin >> N >> M;
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  REP(i,N) {
    if ( col[i] == 0 ) {
      ans *= 3;
      col[i] = 1;
      DFS(i);
    }
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
