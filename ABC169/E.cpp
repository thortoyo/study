#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i,N) cin >> A[i] >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ll ans;
  if (N%2==1) {
    ans = B[N/2] - A[N/2] + 1;
  } else {
    ans = B[N/2-1] + B[N/2] - A[N/2-1] - A[N/2] + 1;
  }
  cout << ans << endl;
}
