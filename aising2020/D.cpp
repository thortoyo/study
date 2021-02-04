#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  ll N;
  string X;
  cin >> N >> X;
  ll ans = 0;
  ll mod=0, tm = 0, tp=0;
  for(ll i=N-1;i>=0;--i) {
    if (X[i] == '1') mod++;
  }
  for(ll i=0; i<N; ++i) {
    tp = (tp * 2) % (mod+1);
    if (X[i] == '1') {
      tp = (tp + 1) % (mod+1);
    }
  }
  if ( mod == 1 ) {
    tm = 0;
  } else {
    for(ll i=0; i<N; ++i) {
      tm = (tm * 2) % (mod-1);
      if (X[i] == '1') tm = (tm + 1) % (mod-1);
    }
  }
//  cout << "mod-1 : " << tm << " ,  mod : " << t << " ,  mod+1 : " << tp << endl;
  vector<ll> pm2(N+1,0), pp2(N+1);
  pp2[0] = 1;
  pm2[0] = 1;
  for( int i=1;i<N+1; ++i ) {
    pp2[i] = (pp2[i-1] * 2) % (mod+1);
  }
  if ( mod != 1 ) {
    for( int i=1;i<N+1; ++i )
      pm2[i] = (pm2[i-1] * 2) % (mod-1);
  }
  for( int i=0; i<N; i++ ) {
    ll subt;
    ans = 1;
    if ( X[i] == '1' ) {
      if ( mod == 1 ) subt = 0, ans = 0;
      else {
        subt = tm - pm2[N-1-i];
//        cout << "i: " << i << ", " << subt << " " << pm2[N-1-i] << endl;
      }
      if ( subt < 0 ) subt += (mod-1);
    } else {
      subt = (tp + pp2[N-1-i]) % (mod+1);
    }
    while (subt != 0) {
      ll a = subt;
      ll pc = 0;
      while (a > 0) {
        pc += (a%2);
        a /= 2;
      }
      subt %= pc;
      ans++;
    }
    cout << ans << endl;
  }
}
