#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(){
  string S;
  cin >> S;
  int n = S.length();
  
  vector<ll> AB(n,0);
  vector<ll> BC(n,0);
  // 3^n のテーブルを作っておく
  vector<ll> n3(n+1);
  n3[0] = 1;
  REP(i,n) n3[i+1] = n3[i]*3 % MOD;

  // B の位置を決めて、それより前にある A の位置も決めた場合に、
  // B よりも前の部分での場合の数
  ll a = 0;
  ll h = 0;
  REP(i,n){
    if (S[i]=='A') a++;
    else if (S[i]=='B')
      AB[i] = ((a * n3[h]) % MOD + (h * n3[h-1]) % MOD) % MOD;
    else if (S[i]=='?') {
      AB[i] = ((a * n3[h]) % MOD + (h * n3[h-1]) % MOD) % MOD;
      h++;
    }
//    cout << AB[i] << " " << a << " " << h << endl;
  }
  
  // B の位置を決めて、それより後ろある C の位置も決めた場合に、
  // B よりも後ろ部分での場合の数
  ll c = 0;
  h = 0;
  REP(i,n){
    if (S[n-i-1]=='C') c++;
    else if (S[n-i-1]=='B')
      BC[n-1-i] = ((c * n3[h]) % MOD + (h * n3[h-1]) % MOD) % MOD;
    else if (S[n-i-1]=='?') {
      BC[n-1-i] = ((c * n3[h]) % MOD + (h * n3[h-1]) % MOD) % MOD;
      h++;
    }
  }
  ll ans = 0;
  REP(i,n){
//    cout << AB[i] << " " << BC[i] << endl;
    if (S[i]=='B' || S[i]=='?') {
      ans = (ans + AB[i] * BC[i]) % MOD;
    }
  }
  cout << ans << endl;
}

