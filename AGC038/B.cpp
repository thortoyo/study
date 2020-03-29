#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

struct SegmentTree_max {
  vector< int > st;
  int N, IVAL;
  SegmentTree_max(int n, int ival = 0) {
    N = 1; IVAL = ival;
    while (N < n) N *= 2;
    st.resize(2*N-1);
    REP(i,N) st[i] = IVAL;
  }
  void add( int i, int val ) {
    i = i + N-1;
    st[i] = val;
    while( i > 0 ) {
      i = (i-1)/2;
      st[i] = max(st[i], val);
    }
  }
  int get( int a, int b, int i, int l, int r ) {
    if ( (b <= l) || (r <= a) ) return IVAL;
    if ( (a <= l) && (r <= b) ) return st[i];
    int lv = get(a,b, i*2+1, l, (l+r)/2 );
    int rv = get(a,b, i*2+2, (l+r)/2, r );
    return max(lv,rv);
  }
  int getN() { return N; }
  void disp() {
    int i = 1, m=0;
    while (1<<(i-1) <= N) {
      REP(j, 1<<(i-1))
        cout << st[m++] << " ";
      cout << endl;
      i++;
    }
  }
};
struct SegmentTree_min {
  vector< int > st;
  int N, IVAL;
  SegmentTree_min(int n, int ival = 10000000) {
    N = 1; IVAL = ival;
    while (N < n) N *= 2;
    st.resize(2*N-1);
    REP(i,N) st[i] = IVAL;
  }
  void add( int i, int val ) {
    i = i + N-1;
    st[i] = val;
    while( i > 0 ) {
      i = (i-1)/2;
      st[i] = min(st[i], val);
    }
  }
  int get( int a, int b, int i, int l, int r ) {
    if ( (b <= l) || (r <= a) ) return IVAL;
    if ( (a <= l) && (r <= b) ) return st[i];
    int lv = get(a,b, i*2+1, l, (l+r)/2 );
    int rv = get(a,b, i*2+2, (l+r)/2, r );
    return min(lv,rv);
  }
  int getN() { return N; }
  void disp() {
    int i = 1, m=0;
    while (1<<(i-1) <= N) {
      REP(j, 1<<(i-1))
        cout << st[m++] << " ";
      cout << endl;
      i++;
    }
  }
};


int main() {
  int N,K;
  cin >> N >> K;
  vector< int > P(N);
  vector< bool > s(N, true);
  SegmentTree_max stmax(N);
  SegmentTree_min stmin(N);
  REP(i,N) {
    cin >> P[i];
    stmax.add(i,P[i]);
    stmin.add(i,P[i]);
  }
  int ans = 1;
  // KŒÂ‚ª¸‡‚©‚ğ’²‚×‚Ä‚¨‚­
  int cnt = 1;
  REP(i,N-1) {
    if ( P[i] <= P[i+1] ) cnt++;
    else cnt = 1;
    if ( i - (K-2) >= 0 ) {
      if (cnt >= K) s[i-(K-2)] = true;
      else s[i-(K-2)] = false;
    }
  }
  bool flg = false;
  if ( s[0] ) flg = true;
  REP(i,N-K) {
    int ma = stmax.get(i,i+K+1,0,0,stmax.getN());
    int mi = stmin.get(i,i+K+1,0,0,stmax.getN());
//    cout << i << " : " << ma << " " << mi << endl;
    if ( (P[i] == mi) && (P[i+K] == ma) ) continue;
    if ( s[i+1] ) {
      if ( flg ) continue;
      else flg = true;
    }
    ans++;
  }
  cout << ans << endl;
//  stmax.disp();
//  stmin.disp();
}


