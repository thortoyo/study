#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll A[212345];

ll solve() {
  int N;
  cin >> N;
  map<int,int> m;
  ll ans = 0;
  REP(i,N) {
    ll a;
    cin >> a;
    ans += m[a%200];
    m[a%200]++;
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
