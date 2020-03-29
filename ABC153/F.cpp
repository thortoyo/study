#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// imos�@
// ��Ԃ̃_���[�W��imos�@���g���ėݐςŋ��߂�B
// �͈͂��L���̂ŁA�����X�^�[�ʒu�Ŕ͈͂��Ǘ��B
// �͈͂ɓ����Ă��邩�̔���� lower_bound �ōs���B

ll total[200020];

int main() {
  ll N,D,A;
  cin >> N >> D >> A;
  vector< pair<ll,ll> > mon(N);
  REP(i,N) {
    cin >> mon[i].first >> mon[i].second;
    mon[i].second = (mon[i].second+A-1) / A;
  }
  sort( mon.begin(), mon.end() );
  ll ans = 0;
  REP(i,N) {
    mon[i].second -= total[i];
    if ( mon[i].second > 0 ) {
      // ���݂̗ݐσ_���[�W���̗͂��Ⴏ��΁A���e��u��
      total[i] += mon[i].second;
      ans += mon[i].second;
      // ���e�͈͊O�ɂȂ�ŏ��̃����X�^�[�ʒu�ŁA�ݐσ_���[�W������
      auto it = lower_bound( mon.begin(), mon.end(), make_pair(mon[i].first+2*D+1, -1LL<<60));
      ll x = distance(mon.begin(), it);
      total[x] -= mon[i].second;
    }
    total[i+1] += total[i];
  }
  cout << ans << endl;
}
