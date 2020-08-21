#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  string c;
  cin >> N >> c;
  int wn = 0;
  int rr = 0;
  int ans = 0;
  REP(i,N) if ( c[i] == 'W' ) wn++;
  if ( wn != 0 && wn != N ){
    REP(i,wn) if ( c[N-wn+i] == 'R' ) rr++;
    ans = rr;
  }
  cout << ans << endl;

}
