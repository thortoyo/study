#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

int ma[10] = { 0,2,5,5,4,5,6,3,7,6 };

// dp[i] : i�{�g�������̍ő�l
string dp[10020];

void str_max( string& a, string& b ) {
  if ( a.size() < b.size() ) {
    a = b;
  } else if ( a.size() == b.size() ) {
    if ( b > a ) a = b;
  }
  return;
} 
int main() {
  int N, M;
  cin >> N >> M;
  vector< int > A(M);
  REP(i,M) {
    cin >> A[i];
  }
  // "-"�������l�Ƃ���B�����l�̏ꍇ�́A���̖{���ɂȂ邱�Ƃ��Ȃ����Ƃ������B
  // �͂��߂͕s�v���Ǝv���Ă����ǁAdp[0] = "" �̏�ԂƁA���݂��Ȃ��͈Ⴄ�B
  // ���݂��Ȃ��ꍇ�͂���dp[i]���N�_�Ƃ��邱�Ƃ��ł��Ȃ��B
  REP(i,N) dp[i] = "-";

  dp[0] = "";
  REP(i,N+1) {
    for ( auto x: A ) {
      // ���݂��Ȃ��ꍇ�͔�΂�
      if ( dp[i] == "-" ) continue;
      string b = dp[i] + (char)('0'+x);
      str_max( dp[i+ma[x]], b );
    }
  }
  
  cout << dp[N] << endl;
}
