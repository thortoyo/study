#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int solve() {
  int N,M,K;
  cin >> N >> M;
  vector<int> A(M),B(M);
  REP(i,M) cin >> A[i] >> B[i];
  cin >> K;
  vector<int> C(K),D(K);
  REP(i,K) cin >> C[i] >> D[i];

  int ans = 0;
  REP(i, (1<<K)) {
    vector<int> s(N+1);
    REP(j,K){
      if ( i & (1 << j) ) s[ C[j] ] = 1;
      else  s[ D[j] ] = 1;
    }
    int num = 0;
    REP(j,M){
      if (( s[A[j]] != 0) && ( s[B[j]] != 0) )  num++;
    }
    ans = max( num, ans);
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
