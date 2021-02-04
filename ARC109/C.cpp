#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

char janken(char a, char b){
  if ( ((a == 'R') && (b == 'P')) || ((a == 'P') && (b == 'S')) || ((a == 'S') && (b == 'R')))
    return b;
  else
    return a;
}

int main() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = s + s;
  n *= 2;
  vector< vector<char> > win(n, (vector<char>)(k+1));
  REP(j,k+1) {
    REP(i,n) {
      if (j==0) {
        win[i][j] = s[i];
      }
      else {
        win[i][j] = janken( win[i][j-1], win[(i+modpow(2,j-1,n))%n][j-1]);
//        cout << i << " " << j << " : ";
//        cout <<  win[i][j-1] << " " <<  win[(i+modpow(2,j-1,n))%n][j-1] << " : ";
//        cout << " " << win[i][j] << endl;
      }
    }
  }

  cout << win[0][k] << endl;
}
