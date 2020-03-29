// 重み付きUnion-Find で実装してみる

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

template <typename T = int>
struct UnionFind {
  vector<int> par;	// 親ノード
  vector<int> rank;	// ランク（経路圧縮しなかった場合の木の高さ。rootノードでのみ有効な値が入っている）
  vector<T> dif_weight;	// ルートノードからの重み差分
  UnionFind( int n, T offset = 0) {
    init(n, offset);
  }
  void init( int n, T offset = 0 ) {
    par.resize(n);
    rank.resize(n);
    dif_weight.resize(n);
    for(int i=0; i<n; ++i )  par[i] = i;
    for(int i=0; i<n; ++i )  rank[i] = 0;
    for(int i=0; i<n; ++i )  dif_weight[i] = offset;
  }
  int root( int a ) {
    int pa = par[a];
    if ( pa == a ) return a;
    int r = root(pa);
    dif_weight[a] += dif_weight[par[a]];
//printf(" root( %d ) : %d\n",a,dif_weight[a]);
    return par[a] = r;
  }
  int weight( int a ) {
    root(a);
    return dif_weight[a];
  }
  int diff( int a, int b ) {
    return weight(b) - weight(a);
  }
  bool merge( int a, int b, T w ) {
    T bw = w;
    w += weight(a);
    w -= weight(b);
    int ra = root(a);
    int rb = root(b);
    if ( ra == rb ) return false;
    if ( rank[ra] < rank[rb] ) swap(ra,rb), w = -w;
    if ( rank[ra] == rank[rb] ) rank[ra]++;
    par[rb] = ra;
    dif_weight[rb] = w;
//printf(" merge( %d %d %d ) : %d\n",a,b,bw,w);
    return true;
  }
  bool isSame( int a, int b) {
    return (root(a) == root(b));
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind<int> uf(N);
  REP(i,M) {
    int l,r,d;
    cin >> l >> r >> d;
    l--; r--;
    if ( uf.isSame( l, r ) ) {
      if ( d != uf.diff(l,r) ) {
//printf("%d %d %d %d\n",l,r,d,uf.diff(l,r));
        cout << "No" << endl;
        return 0;
      }
    } else {
      uf.merge(l,r,d);
    }
  }
  cout << "Yes" << endl;
}

