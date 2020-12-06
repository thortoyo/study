#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N,W;
  cin >> N >> W;
  vector<ll> yu(200010,0);
  REP(i,N) {
    ll s,t,p;
    cin >> s >> t >> p;
    yu[s] += p;
    yu[t] -= p;
  }
  for(int i=1;i<200010;i++) yu[i] += yu[i-1];
  bool ok = true;
  REP(i,200010) {
    if (yu[i] > W) ok=false;
  }
  if (ok) 
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
