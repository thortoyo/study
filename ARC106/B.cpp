#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<ll> a(200005);
vector<ll> b(200005);

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size; // size[i]:iがrootの時のメンバ数
    vector<ll> totala;
    vector<ll> totalb;

    UnionFind(int N) : par(N), size(N), totala(N), totalb(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
        for(int i = 0; i < N; i++) totala[i] = a[i];
        for(int i = 0; i < N; i++) totalb[i] = b[i];
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int get_size(int x) {
        return size[root(par[x])];
    }

    ll get_totala(int x) {
        return totala[root(par[x])];
    }
    ll get_totalb(int x) {
        return totalb[root(par[x])];
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
        totala[ry] += totala[rx];
        totalb[ry] += totalb[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
  int N,M;
  cin >> N >> M;
  REP(i,N) cin >> a[i];
  REP(i,N) cin >> b[i];
  UnionFind uf(N);
  REP(i,M) {
    int c,d;
    cin >> c >> d;
    c--; d--;
    uf.unite(c,d);
  }
  bool ans = true;
  REP(i,N) {
    if( uf.get_totala(i) != uf.get_totalb(i) ) {
      ans = false;
      break;
    }
  }
  if (ans) cout << "Yes" << endl;
  else  cout << "No" << endl;
}
