#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int A[200010];
int B[200010];

int main() {
  int N;
  cin >> N;
  REP(i,N) cin >> A[i];
  REP(i,N) cin >> B[i];

  int ans = 0;
  REP(bit, 30) {
    vector<int> AM(N),BM(N);
    int mask = ( 1 << (bit+1)) - 1;
    REP(i,N) {
      AM[i] = A[i] & mask;
      BM[i] = B[i] & mask;
    }
    sort(BM.begin(), BM.end());
    ll c = 0;
    REP(i,N) {
      int c01 = lower_bound(BM.begin(), BM.end(), (1<<bit) - AM[i] ) - BM.begin();
      int c10 = lower_bound(BM.begin(), BM.end(), (2<<bit) - AM[i] ) - BM.begin();
      int c11 = lower_bound(BM.begin(), BM.end(), (3<<bit) - AM[i] ) - BM.begin();
      c += (N-c11)+(c10-c01);
    }
    if (c % 2 == 1) ans |= (1 << bit);
//    cout << bit << " : " << c << endl;
  }
  cout << ans << endl;
}
