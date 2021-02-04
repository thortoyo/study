#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];
  ll lv,rv,ans = 0;
  REP(i,N) {
    lv = A[i] * i;
    for (int j=i; j>=0; j--) {
      if (A[i] > A[j]) {
        lv = A[i] * (i-j-1);
        break;
      }
    }
    rv = A[i] * (N-i);
    for (int j=i; j<N; j++) {
      if (A[i] > A[j]) {
        rv = A[i] * (j-i);
        break;
      }
    }
    ans = max(ans, lv+rv);
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
