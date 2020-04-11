#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main(){
  int K;
  cin >> K;
  queue<ll> q;

  for(int i=1;i<10;i++) {
    q.push(i);
  }

  int n = 0;
  while( !q.empty() ){
    ll v = q.front(); q.pop();
    n++;
    if (n == K) {
      cout << v << endl;
      break;
    }
    ll nv = v % 10;
    if ( nv != 0 )
      q.push( v*10+ nv-1 );
    q.push( v*10+ nv );
    if ( nv != 9 )
      q.push( v*10+ nv+1 );
  }
}
