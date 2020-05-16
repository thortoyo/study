#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int to[200010];
ll ord[200010];

int main(){
  ll N,K;
  cin >> N >> K;
  REP(i,N) { cin >> to[i]; to[i]--; }

  REP(i,N+1) ord[i] = -1;
  int v = 0;
  ll num = 0;
  ll nmax = 0;
  ll h = 0;
  while(1) {
//    cout << v << " " << num << " " <<  to[v] << endl;
    if ( ord[v] != -1 ) {
      h = ord[v];
      nmax = num - h;
      break;
    }
    ord[v] = num;
    num++;
    v = to[v];
  }
  if (K > h) {
    K -= h;
    K %= nmax;
    K += h;
  }
  REP(i,N) {
    if (ord[i] == K) {
      cout << i+1 << endl;
      break;
    }
  }
}
