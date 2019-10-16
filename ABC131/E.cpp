#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector< pair<int,int> > A(N);
  int kmax = (N-1)*(N-2)/2;
  if (kmax < K) {
    cout << "-1" << endl;
    return 0;
  }

  REP(i,N-1) {
    cout << "1 " << i+2 << endl;
  }
  int n0 = 2;
  int n1 = 3;
  REP(i,kmax-K) {
    cout << n0 << " " << n1 << endl;
    if (n1==N) { n0++; n1=n0+1; }
    else n1++;
  }
}
