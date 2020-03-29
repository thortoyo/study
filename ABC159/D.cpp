#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  map<int,ll> M;
  
  REP(i,N) {
    cin >> A[i];
    M[ A[i] ]++;
  }
  int mn = 0;
  ll ans = 0;
  for ( auto m: M ) {
    if (m.second > 1 ) 
      ans += (m.second * (m.second-1)/ 2);
  }

  REP(i,N) {
    int mn = M[A[i]];
    ll ans1 = ans - (mn-1);
    cout << ans1 << endl;
  }
}

  
