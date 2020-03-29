#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size; // size[i]:iがrootの時のメンバ数

    UnionFind(int N) : par(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int get_size(int x) {
        return size[root(par[x])];
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
  int N,M,K;
  cin >> N >> M >> K;
  UnionFind uf(N);
  vector< vector<int> > blk(N);
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a,b);
    blk[a].push_back(b);
    blk[b].push_back(a);
  }
  REP(i,K) {
    int c,d;
    cin >> c >> d;
    c--;d--;
    blk[c].push_back(d);
    blk[d].push_back(c);
  }

  REP(i,N) {
    int bcnt = 0;
    for ( auto bk : blk[i] )
      if( uf.same(i,bk) ) bcnt++;
//    cout << i << " : " << uf.get_size(i) << " - " << bcnt << endl;
    int cnt = uf.get_size(i) - 1 - bcnt;
    cout << cnt << " ";
  }
    
/*  
  REP(i,N) {
    int cnt = 0;
    REP(j,N) {
      if (i==j) continue;
      bool flg =false;
      for ( auto bk : blk[i] )
        if (bk == j) flg = true;
      if ( flg ) continue;
      if (uf.same(i,j)) cnt++;
//      cout << i << " - " << j << " : " << cnt << endl;
    }
    cout << cnt << " ";
  }
  */
  cout << endl;
}

  
