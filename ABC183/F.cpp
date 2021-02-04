#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


int C[200010];

struct UnionFind {
  vector<int> par; // par[i]:i�̐e�̔ԍ��@(��) par[3] = 2 : 3�̐e��2
  vector<int> size; // size[i]:i��root�̎��̃����o��
  vector< map<int,int> > m;
  
  UnionFind(int N) : par(N), size(N),m(N) { //�ŏ��͑S�Ă����ł���Ƃ��ď�����
    for(int i = 0; i < N; i++) par[i] = i;
    for(int i = 0; i < N; i++) size[i] = 1;
    for(int i = 0; i < N; i++) m[i][C[i]] = 1;
  }

  int root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  int get_size(int x) {
    return size[root(par[x])];
  }

  map<int,int> get_m(int x) {
    return m[root(par[x])];
  }

  void unite(int x, int y) { // x��y�̖؂𕹍�
    int rx = root(x); //x�̍���rx
    int ry = root(y); //y�̍���ry
    if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
    if (m[rx].size() > m[ry].size()) swap(rx,ry);
    par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
    size[ry] += size[rx];
//    cout << ry << " <- " << rx << " : " << endl;
    for ( auto mm : m[rx] ) {
      m[ry][mm.first] += mm.second;
//      cout << "  " << mm.first << ":" << mm.second << "  ";
//      cout << "  " << mm.first << ":" << m[ry][mm.first] << endl;
    }
  }

  bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
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
