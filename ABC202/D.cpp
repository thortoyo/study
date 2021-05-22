#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[2002][2002];

/*
    �O����: O(MAX_N*MAX_N)
    nCk(n,k): nCk �̌v�Z�BO(1)
*/
const int MAX_N = 61;         // n �̍ő�l
vector<vector<long long>> com;  // �O�v�Z�̌��ʂ�ۑ�

// ���I�v��@�őO����
void init() {
    com.assign(MAX_N, vector<long long>(MAX_N));
    com[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_N; j++) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
        }
    }
}
// nCk ���擾
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return com[n][k];
}

string solve() {
  init();
  ll a,b,k;
  cin >> a >> b >> k;
  k--;
  ll n = 0;
  ll ab = a+b;
  string ans = "";
  // i = 0 : 0*****
  // i = 1 : 1*****
  // i = 2 : 11****
  // i=0, j=0 : 0 
  REP(i, ab){
    if ( a == 0 ) {
      ans += "b";
    } else if (k >= nCk( a+b-1, b ) ) {
      // ���̌���b
      ans += "b";
      k -= nCk( a+b-1, b );
      b--;
    } else {
      // ���̌���a
      ans += "a";
      a--;
    }
//    cout << a << " " << b << " " << k << " : " << ans << endl;
  }
  return ans;
}

int main(){
  cout << solve() << endl;
}
