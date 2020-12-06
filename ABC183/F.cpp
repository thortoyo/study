#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


int C[200010];

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> size; // size[i]:iがrootの時のメンバ数
  vector< map<int,int> > m;
  
  UnionFind(int N) : par(N), size(N),m(N) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) par[i] = i;
    for(int i = 0; i < N; i++) size[i] = 1;
    for(int i = 0; i < N; i++) m[i][C[i]] = 1;
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  int get_size(int x) {
    return size[root(par[x])];
  }

  map<int,int> get_m(int x) {
    return m[root(par[x])];
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    if (m[rx].size() > m[ry].size()) swap(rx,ry);
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    size[ry] += size[rx];
//    cout << ry << " <- " << rx << " : " << endl;
    for ( auto mm : m[rx] ) {
      m[ry][mm.first] += mm.second;
//      cout << "  " << mm.first << ":" << mm.second << "  ";
//      cout << "  " << mm.first << ":" << m[ry][mm.first] << endl;
    }
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N,Q;
  cin >> N >> Q;
  REP(i,N) cin >> C[i];

  UnionFind uf(N);
  REP(i,Q) {
    int cmd,a,b;
    cin >> cmd >> a >> b;
    a--; b--;
    if ( cmd == 1 ) {
      uf.unite(a,b);
    } else {
      b++;
      auto mm = uf.get_m(a);
      cout << mm[b] << endl;
    }
  }
}
