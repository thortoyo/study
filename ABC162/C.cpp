#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int GCD(int a, int b) {
  if ( a%b==0 ) return b;
  return GCD(b, a%b);
}

int main(){
  int K;
  cin >> K;

  int ans = 0;
  for( int i=1; i<=K; ++i ) 
    for( int j=1; j<=K; ++j ) 
      for( int k=1; k<=K; ++k ) {
        ans += GCD(i, GCD(j,k));
      }
  cout << ans << endl;

}
