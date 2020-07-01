#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<bool> isp(N+1, true);

void sieve(int N) {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; i*i<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  ll N,M;
  cin >> N >> M;
  sieve();
  
  
  REP(i,N) {
    cin >> A[i];
    all ^= A[i];
  }
  REP(i,N) {
    cout << (all ^ A[i]) << " ";
  }
  cout << endl;

}
