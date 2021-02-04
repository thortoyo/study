#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<ll> a(200005);
vector<ll> b(200005);

struct UnionFind {
    vector<int> par; // par[i]:i�̐e�̔ԍ��@(��) par[3] = 2 : 3�̐e��2
    vector<int> size; // size[i]:i��root�̎��̃����o��
    vector<ll> totala;
    vector<ll> totalb;

    UnionFind(int N) : par(N), size(N), totala(N), totalb(N) { //�ŏ��͑S�Ă����ł���Ƃ��ď�����
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
        for(int i = 0; i < N; i++) totala[i] = a[i];
        for(int i = 0; i < N; i++) totalb[i] = b[i];
    }

    int root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
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

    void unite(int x, int y) { // x��y�̖؂𕹍�
        int rx = root(x); //x�̍���rx
        int ry = root(y); //y�̍���ry
        if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
        par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
        size[ry] += size[rx];
        totala[ry] += totala[rx];
        totalb[ry] += totalb[rx];
    }

    bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
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
