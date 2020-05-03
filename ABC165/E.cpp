#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  for(int i=1; i<M+1; i++) {
    if ( N%2==0 )
      cout << i << " " << (N+1-i) << endl;
    else
      cout << i << " " << (2*M+1-i) << endl;
  }
}
