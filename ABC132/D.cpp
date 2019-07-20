#include <bits/stdc++.h>
using namespace std;
 

const int64_t MOD = 1000000007;
int64_t c[2002][2002];

void init(){
  c[0][0] = 1;
  for (int i=0; i<2001;++i ) {
    for (int j=0; j<2001;++j ) {
      c[i+1][j] = (c[i+1][j] + c[i][j]) % MOD;
      c[i+1][j+1] += (c[i+1][j+1] + c[i][j]) % MOD;
    }
  }
}

int64_t f2(int n, int k){
//  cout << "f2: " << n << " " << k << endl;
  return c[n][k];
}
int64_t f(int n, int k){
  return f2(n-k, k);
}

int main() {
  int N,K;
  cin >> N >> K;
  init();
 
  for (int i=1;i<=K;++i ) {
    /*
    // Â‚Ìê‡‚Ì”
    int64_t b;
    b = f(K+i-1, i) % MOD;
    // Ô‚Ìê‡‚Ì”
    int64_t r;
    r  = f(N-K+i-1, i-1) % MOD;
    r += f(N-K+i-1, i) % MOD;
    r += f(N-K+i-1, i) % MOD;
    r += f(N-K+i-1, i+1) % MOD;
    cout << b * r % MOD << endl;
*/
    int64_t b;
    b = (f2(N-K+1, i) % MOD) * (f2(K-1, i-1) % MOD) % MOD;
    cout << b << endl;
  }
}
