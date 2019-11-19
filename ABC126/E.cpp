#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int c[100005];

int main() {
  int N,M;
  cin >> N >> M;
  int maxg = 0;
  set< pair<int,int> > s;
  REP(i,M) {
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    if (c[x] == 0 ) {
      if (c[y] == 0) {
        maxg++;
        c[x] = c[y] = maxg;
      } else {
        c[x] = c[y];
      }
    } else {
      if (c[y] == 0) {
        c[y] = c[x];
      } else {
        if (c[x] != c[y]) {
          int a,b;
          a = c[x];
          b = c[y];
          if ( a > b ) swap(a,b);
          s.emplace(a,b);
        }
      }
    }
  }
  
  int ans = maxg - s.size();
  REP(i,N) if (c[i]==0) ans++;
  
//  REP(i,N) cout << i+1 << " "; cout << endl;
//  REP(i,N) cout << c[i] << " "; cout << endl;
//  for( auto x: s ) cout <<  x.first << ", " << x.second << endl;
  
  cout << ans << endl;
  
}

