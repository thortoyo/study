// DP‚Å‰ð‚­•û–@

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int DP[100005];

int main() {
  int X;
  cin >> X;
  DP[0] = 1;
  REP(i,X)
    REP(j,6)
      DP[i+100+j] = DP[i] | DP[i+100+j];

  if (DP[X]==1)
    cout << "1" << endl;
  else
    cout << "0" << endl;

}
