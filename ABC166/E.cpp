#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];
  map<int,int> m;
  ll ans = 0;
  REP(i,N) {
    // ©•ª‚æ‚è¶‚Ì€–Ú‚Æˆê’v‚·‚é‚Ì‚ğ‰ÁZ
    if (i != 0 ) ans += m[i+1-A[i]];
    m[i+1+A[i]]++;
  }
  cout << ans << endl;
}
