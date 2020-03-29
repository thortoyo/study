#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

struct SegmentTree {
private:
    int n;
    vector<int> node;
public:
    SegmentTree(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void add(int k, int val) {
        k += (n - 1);
        node[k] += val;

        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};


int main() {
  int N, Q;
  string S;
  cin >> N >> S >> Q;
  vector< SegmentTree > seg(26, SegmentTree(vector<int>(N, 0)) );
  vector< vector< int > > CA(26, vector<int>(N+1,0));
  REP(i,N) {
    CA[S[i]-'a'][i+1] = 1;
  }
  REP(i,N) {
    REP(j,26) CA[j][i+1] += CA[j][i];
  }
  REP(i,Q) {
    int a;
    cin >> a;
    if ( a==1 ) {
      int b;
      string c;
      cin >> b >> c;
      b--;
      if ( S[b] != c[0] ) {
        seg[S[b]-'a'].add(b, -1);
        seg[c[0]-'a'].add(b, 1);
        S[b] = c[0];
      }
    } else {
      int l,r;
      cin >> l >> r;
      int num = 0;
      REP(j,26) {
        if ( (CA[j][r] - CA[j][l-1]) + seg[j].getsum(l-1,r) > 0) num++;
      }
      cout << num << endl;
    }
  }
}
