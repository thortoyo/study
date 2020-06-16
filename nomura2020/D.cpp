#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size; // size[i]:iがrootの時のメンバ数
    vector<bool> mitei; // iがrootの時にそれが未定グループかどうか

    UnionFind(int N) : par(N), size(N), mitei(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) size[i] = 1;
        for(int i = 0; i < N; i++) mitei[i] = false;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int get_size(int x) {
        return size[root(par[x])];
    }
    bool get_mitei(int x) {
        return mitei[root(par[x])];
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
        mitei[ry] = mitei[rx];
    }

    void set_mitei(int x) { // xの所属グループを未定にする
        int rx = root(x); //xの根をrx
        mitei[rx] = true;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
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

