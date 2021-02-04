#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


const ll INF = 1LL << 60;

ll dp[100005];

// セグメントツリー
//  範囲内の要素数を返す
template <typename T = int>
struct SegmentTree {
  int N;
  vector< set<T> > node;
  set<T> ival;
  SegmentTree( int size, T iv = 0 ) {
    init(size, iv);
  }
  void init( int size, T iv = 0 ) {
    N = 1; while( N < size ) N<<=1;
    node.resize( 2*N-1 );
    ival = iv;
  }
  void update( int pos, T dat ) {
    pos = N + pos - 1;
    node[pos].insert( dat );
    while ( pos > 0 ) {
      pos = (pos-1)/2;
      node[pos].insert( dat );
    }
  }
  // [a,b) 区間から取得。現在位置 k, 現在位置の範囲[l,r)
  T get( int a, int b, int k, int l, int r ) {
    if (a>=r || b<=l) return ival;
    if (a<=l && b>=r) return node[k];
    T vl = get( a, b, 2*k+1, l, (l+r)/2 );
//    cout << " vl : " << a << " " <<  b  << " " << 2*k+1 << " " << l << " " << (l+r)/2<< " -> " << vl << endl;
    T vr = get( a, b, 2*k+2, (l+r)/2, r );
//    cout << " vr : " << a << " " <<  b  << " " << 2*k+2 << " " << (l+r)/2 << " " << r << " -> " << vr << endl;
    return min(vl,vr);
  }
  void print() {
    cout << "---- node " << endl;
    for ( int i=0; i<2*N-1; ++i ) {
      cout << " " << i << " : " << node[i] << endl;
    }
  }
};

int main() {
  int N,Q;
  cin >> N >> Q;
  vector< int > c(N), cr_pos(N), ans(Q);
  vector< tuple<int, int, int> > rl(N);
  SegmentTree<int> col(N);
  REP(i,N) cin >> c[i];
  REP(i,Q) {
    int l,r;
    cin >> l >> r;
    l--; r--;
    rl.emplace_back( r, l, i );
  }
  sort( rl.begin(), rl.end() );

  // r 
  REP(i,N) dp[i] = INF;
  dp[0] = 0;
  
  st.update( 0, dp[0] );
//  st.print();
  REP(i,M) {
    int l,r,c;
    tie(r,l,c) = q[i];
    ll val = st.get(l,r+1,0,0,st.getRMax()) + c;
//    printf("%d %d %d : %lld %lld\n",r,l,c,val,dp[r]);
    if ( dp[r] > val ) {
      dp[r] = val;
      st.update( r, val );
//      st.print();
    }
  }
//  REP(i,N) cout << dp[i] << endl;

  cout << ((dp[N-1]==INF) ? -1 : dp[N-1]) << endl;
}
