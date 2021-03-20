#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int solve() {
  int N,M;
  cin >> N  >> M;
  vector<int> A(N+1), C(N+2,0);
  REP(i,N) cin >> A[i];
  A[N] = N;
  REP(i,M) C[ A[i] ]++;
  int ans = N;
  REP(i,N) {
    if ( C[i] == 0 ) {
      ans = i;
      break;
    }
  }
  REP(i,N-M) {
    C[A[i]]--;
    C[A[i+M]]++;
    if ( C[A[i]] == 0 ) {
      ans = min( ans, A[i] );
    }
  }

  return ans;
}

int main(){
  cout << solve() << endl;
}
