#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  REP(i,T) {
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    cout << floor_sum(n,m,a,b) << endl;
  }
}
