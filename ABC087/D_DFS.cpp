#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

vector< vector< pair<int,int> > > to(100005);
vector< ll > pos(100005, INF);
set<int> A;

bool DFS( int v ) {
  bool ok = true;
//  cout << v << " : " << pos[v] << endl;
  for ( auto nv : to[v] ) {
//    cout << " " << nv.first << ", " << nv.second << " : " << pos[nv.first] << endl;
    if ( pos[nv.first] == INF ) {
      pos[nv.first] = pos[v] + nv.second;
      if (pos[nv.first] > 1000000000 && pos[nv.first] != INF) return false;
      ok = DFS( nv.first );
      if (!ok ) return ok;
    } else {
      if ( pos[nv.first] != pos[v] + nv.second ) {
//        cout << " false" << endl;
        return false;
      }
    }
  }
  return ok;
}

int main() {
  int N, M;
  cin >> N >> M;
  REP(i,M) {
    int l,r,d;
    cin >> l >> r >> d;
    to[l].emplace_back( r, d );
    to[r].emplace_back( l, -d );
    A.emplace(r);
    A.emplace(l);
  }
  for ( auto v : A ) {
    if ( pos[v] != INF ) continue;
    pos[v] = 0;
    if ( DFS( v ) == false ) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

