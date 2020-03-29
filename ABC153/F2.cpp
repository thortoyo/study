#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

// �\�[�g���Ē[���珇�ɏ������Ă����B
// ���[��Ώ�����ꍇ�ɂ́A���̒[�̈ʒu+D �ɔ��e��u���̂��œK�B�����荶�̈ʒu��
// �����Ă��������Ƃ͂Ȃ����A������E�̈ʒu�ɒu���ƁA���[�ɓ�����Ȃ��Ȃ�B
// �u�����́A���[�����X�^�[�̓|���񐔕��B
// �u�������e�̈ʒu�ƌ����Ǘ����Ă����āA���[���珇�Ƀ����X�^�[�����Ă����B
// ���e�͈͓̔��ŁA���̌��œ|���Ȃ�A��������K�v�Ȃ��B
// ���e�͈͓̔��ŁA���̌��œ|��Ȃ��Ȃ�A+D �ʒu�ɓ|�����̔��e��u���B
// ���e�͈̔͊O�Ȃ�A���e�̏����폜���A+D �ʒu�ɓ|�����̔��e��u���B
// ���e�� queue �ŊǗ�����H
// 	D = 2
// 	0 1 2 3 4 5 6 7 8
// 	H 
// 	----B----
// 
// �S�����X�^�[�̃��[�v�� O(N) �ŁA���̒��Ŗ��񔚒e�̃L���[��S���񂵂Ă���̂�
// �ň� O(N^2) �ɂȂ��Ă�����ۂ��B
// �̗͂�0�ȉ��ɂȂ�����A�L���[�̒T�����~�߂���H
//  �� TLE
//     ��������񂾂낤���ǁA(2*10^5)^2 ���瑽��������1/10�Ƃ�1/100�ɂȂ��Ă��A
//     �܂��Ԃɍ���Ȃ����Ă��Ƃ炵���B
// �����ƁA�_���[�W���ڎ�肵�Ȃ��ƃ_�����E�E�E
// ���e��u������A���̌����g�[�^�����ɉ��Z�B
// �ʒu�����e�͈͂𒴂��Ă���A���̒��������e�̌����g�[�^����������B

int main() {
  ll N,D,A;
  cin >> N >> D >> A;
  vector< pair<ll,ll> > mon(N);
  REP(i,N) {
    cin >> mon[i].first >> mon[i].second;
    mon[i].second = (mon[i].second+A-1) / A;
  }
  sort( mon.begin(), mon.end() );
  deque< pair<ll,ll> > q;
  ll ans = 0;
  ll total = 0;
  REP(i,N) {
    while ( !q.empty() ) {
      auto nq = q.front();
      if ( nq.first < mon[i].first ) {
        total -= nq.second;
        q.pop_front();
      } else {
        break;
      }
    }
    mon[i].second -= total;
    if ( mon[i].second > 0 ) {
      q.emplace_back( mon[i].first + 2 * D, mon[i].second );
      ans += mon[i].second;
      total += mon[i].second;
    }
  }
  cout << ans << endl;
}
