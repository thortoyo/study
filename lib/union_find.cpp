#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


struct UnionFind {
    vector<int> par; // par[i]:i�̐e�̔ԍ��@(��) par[3] = 2 : 3�̐e��2
    vector<int> size; // size[i]:i��root�̎��̃����o��

    UnionFind(int N) : par(N), size(N) { //�ŏ��͑S�Ă����ł���Ƃ��ď�����
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
    }

    int root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int get_size(int x) {
        return size[root(par[x])];
    }

    void unite(int x, int y) { // x��y�̖؂𕹍�
        int rx = root(x); //x�̍���rx
        int ry = root(y); //y�̍���ry
        if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
        par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
        size[ry] += size[rx];
    }

    bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
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
    
  cout << endl;
}

  


// Union-Find�؂̃e�X�g
//  �����N�����

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

struct UnionFind {
  vector<int> par;	// �e�m�[�h
  vector<int> rank;	// �����N�i�o�H���k���Ȃ������ꍇ�̖؂̍����Broot�m�[�h�ł̂ݗL���Ȓl�������Ă���j
  UnionFind( int n ) {
    init(n);
  }
  void init( int n ) {
    par.resize(n);
    rank.resize(n);
    for(int i=0; i<n; ++i )  par[i] = i;
    for(int i=0; i<n; ++i )  rank[i] = 0;
  }
  int root( int a ) {
    int pa = par[a];
    if ( pa == a ) return a;
    return par[a] = root(pa);
  }
  bool merge( int a, int b ) {
    int ra = root(a);
    int rb = root(b);
    if ( ra == rb ) return false;
    if ( rank[ra] < rank[rb] ) swap(ra,rb);
    if ( rank[ra] == rank[rb] ) rank[ra]++;
    par[rb] = ra;
    return true;
  }
  bool isSame( int a, int b) {
    return (root(a) == root(b));
  }
  int CountRoot( int n ) {
    int cnt = 0;
    for (int i=0; i<n; ++i )
      if ( i == par[i] ) cnt++;
    return cnt;
  }
};

int main() {
  int N,M;
  cin >> N >> M;
  UnionFind uf(N);
  REP(i,M) {
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    uf.merge(x,y);
  }
  
  cout << uf.CountRoot(N) << endl;
  
}


