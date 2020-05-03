#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  string S;
  cin >> S;
  ll N = S.length();
  ll ten = 1;
  ll cur = 0;
  vector<ll> v(2020,0);
  
  REP(i,N) {
    cur = (cur + (S[N-1-i]-'0') * ten ) % 2019;
    ten = (ten * 10) % 2019;
    v[cur]++;
//    cout << S[N-1-i] << " " << cur << endl;
  }
  v[0]++;
  ll ans = 0;
  REP(i,2019) {
    ans += v[i] * (v[i]-1) / 2;
  }
  cout << ans << endl;
}
