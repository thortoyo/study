#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
  ll N;
  string X;
  cin >> N >> X;
  ll lnum = N * 2;

  ll cnt = 1;
  bool exist01 = true;
  bool exist10 = true;
  REP(i,N) {
    if (X[i] == '1') {
      cnt = (cnt * 2) % MOD;
    } else {
      cnt = (cnt * 2 - 1) % MOD;
    }
//    cout << cnt << " " << exist01 << " " << exist10 << endl;
    if (exist10 && (i%2==0) && X[i]=='0') exist10 = false;
    if (exist01 && (i%2==1) && X[i]=='0') exist01 = false;
  }
  if (exist10) cnt = (cnt-1) %MOD;
  if (exist01) cnt = (cnt-1) %MOD;
//  cout << cnt << " " << exist01 << " " << exist10 << endl;
  ll ans = 0;
  ans = (lnum * cnt) % MOD;
  if (exist10) ans = (ans + 2) % MOD;
  if (exist01) ans = (ans + 2) % MOD;

  cout << ans << endl;
}
