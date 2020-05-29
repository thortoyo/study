#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll x[100005];
ll y[100005];

int main(){
  ll N,Q;
  cin >> N >> Q;

  REP(i,N) {
    x[i] = i;
    y[i] = i;
  }
  bool t = false;
  REP(i,Q) {
    int c,a,b;
    cin >> c;
    if ( c!=3 ) { cin >> a >> b; a--; b--; }
    if ( (t && c==2) || (!t && c==1)) {
      // y•ûŒü“ü‚ê‘Ö‚¦
      swap( y[a],y[b] );
    } else if ( (!t && c==2) || (t && c==1)) {
      // x•ûŒü“ü‚ê‘Ö‚¦
      swap( x[a],x[b] );
    } else if ( c==3 ) {
      // “]’u
      t = !t;
    } else {
      // •\Ž¦
      if (t) swap(a,b);
      cout << (N*y[a] + x[b]) << endl;
    }
  }
}

