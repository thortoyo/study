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

