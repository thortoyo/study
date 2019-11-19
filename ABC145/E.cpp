// �H�ׂ���̂�I�񂾏ꍇ�A���̒��ōŌ�ɐH�ׂ�͕̂K����Ԏ��Ԃ���������̂ɂȂ�B
// ����𗘗p���AAi���\�[�g���Ă����āA�i�b�v�T�b�NDP����ƁA
// DP[i][] �� 0�`i-1 �܂ł̐H�ו���I��ŐH�ׂ��ꍇ�̍ő�l�ɂȂ��Ă���͂��B
//  �Ⴆ�� 0,1,5,i-1 ��I�Ԃ̂��x�X�g�������Ƃ��Ă��A0,1,2,10,i-5 ���x�X�g�������Ƃ��Ă�
//  ���ǂ� DP[i][] �ɂ��̃x�X�g�̒l�������Ă���B
// �Ȃ̂ŁADP[i][] + i+1�`N-1 �̂ǂꂩ �� i �ȏオ�Ō�ɐH�ׂ���̂������ꍇ��MAX
// ����� i ��U���đS���݂���A�������o�Ă���B

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

ll dp[3005][3005];

int main() {
  ll N, T;
  cin >> N >> T;
  vector<pair<int,int> > AB(N);
  REP(i,N) {
    int a,b;
    cin >> a >> b;
    AB[i] = make_pair(a,b);
  }
  sort( AB.begin(), AB.end() ) ;
//  REP(i,N) cout << AB[i].first << " " << AB[i].second << endl;
  REP(i,N) {
    REP( ti, T ) {
      if ( ti >= AB[i].first) dp[i+1][ti] = max(dp[i][ti-AB[i].first] + AB[i].second, dp[i][ti] );
      else dp[i+1][ti] = dp[i][ti];
    }
  }
  ll ans = 0;
  REPI(i,0,N-1) {
    REPI(j,i+1,N) {
      ans = max( ans, dp[i+1][T-1] + AB[j].second );
    }
  }
//  REP(i,T) {
//    REP(j,N+1) {
//      printf("%3d ",dp[j][i]);
//    }
//    cout << endl;
//  }

  cout << ans << endl;
}
