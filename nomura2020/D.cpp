#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct UnionFind {
    vector<int> par; // par[i]:i�̐e�̔ԍ��@(��) par[3] = 2 : 3�̐e��2
    vector<int> size; // size[i]:i��root�̎��̃����o��
    vector<bool> mitei; // i��root�̎��ɂ��ꂪ����O���[�v���ǂ���

    UnionFind(int N) : par(N), size(N), mitei(N) { //�ŏ��͑S�Ă����ł���Ƃ��ď�����
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
        for(int i = 0; i < N; i++) mitei[i] = false;
    }

    int root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int get_size(int x) {
        return size[root(par[x])];
    }
    bool get_mitei(int x) {
        return mitei[root(par[x])];
    }

    void unite(int x, int y) { // x��y�̖؂𕹍�
        int rx = root(x); //x�̍���rx
        int ry = root(y); //y�̍���ry
        if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
        par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
        size[ry] += size[rx];
        mitei[ry] = mitei[rx];
    }

    void set_mitei(int x) { // x�̏����O���[�v�𖢒�ɂ���
        int rx = root(x); //x�̍���rx
        mitei[rx] = true;
    }

    bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  int N;
  cin >> N;
  UnionFind uf(N);
  vector<int> a(N+1);
  ll mitei_n = 0;
  REP(i,N) {
    int p;
    cin >> p;
    if (p == -1) {
      uf.set_mitei(i);
      mitei_n++;
    } else {
      p--;
      uf.unite(p, i);
    }
  }
  ll grp=0;
  ll base = 0;
  ll kaku = 0;
  vector<ll> mv;
  REP(i,N) {
//    cout << i << " " << uf.root(i) << endl;
    if (i==uf.root(i)) {
      grp++;
      if ( uf.get_mitei(i) ) {
        mv.push_back( uf.get_size(i) );
      } else {
        kaku += uf.get_size(i);
      }
      base += uf.get_size(i) - 1;
    }
  }
  ll ans = base * modpow(N-1, mitei_n, MOD) % MOD;
  cout << ans << endl;
  ll pre_m = 0;
  for ( auto v: mv) {
    ans = (ans +  (kaku + pre_m) * modpow(N-1, mitei_n-1, MOD)) % MOD;
    cout << ans << " " << kaku << " " << pre_m << endl;
    pre_m += v;
  }
  cout << ans << endl;
}

