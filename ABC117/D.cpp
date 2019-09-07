// https://atcoder.jp/contests/abc117/tasks/abc117_d
// ��蕶
// N �̔񕉐��� A1,A2,...,AN ����є񕉐��� K ���^�����܂��B
// 0 �ȏ� K �ȉ��̐��� X �ɑ΂��āAf(X)=(X XOR A1) + (X XOR A2) + ... + (X XOR AN) �Ƃ��܂��B
// �����ŁA�񕉐��� a,b �ɑ΂��� a XOR b �� a �� b �̃r�b�g���Ƃ̔r���I�_���a��\���܂��B
// f �̍ő�l�����߂Ă��������B
// ����
// ���͂͑S�Đ����ł���
// 1 ? N ? 10^5
// 0 ? K ? 10^12
// 0 ? Ai ? 10^12
//
// ����
// ���͈͂ȉ��̌`���ŕW�����͂���^������B
// N K
// A1 A2 ... AN
//
// �o��
// f �̍ő�l���o�͂���B
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()


vector< vector<ll> > dp(51, vector<ll>(2,-1));

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  
  REP(i,N) cin >> A[i];

  dp[50][0] = 0;
  dp[50][1] = -1;
  for( int b=50-1; b>=0; --b ) {
    ll mask = 1LL << b;
    ll cnt1 = 0;
    REP(i,N) {
      if ( A[i] & mask ) cnt1++;
    }

    // Xi �Ƃ��� 0 or 1 ��I�񂾎��̃X�R�A
    ll score0 = cnt1 * mask;
    ll score1 = (N-cnt1) * mask;
    
    // dp[i][0] : i bit�ڂ܂ł̍��v�l�A���bit��K�ƈ�v
    // dp[i][1] : i bit�ڂ܂ł̍��v�l�A���bit��K����������

    // dp[i+1][0] <= dp[i][0] : Xi == Ki �Ȃ̂ŁAKi ������score0/1�����Z
    dp[b][0] = dp[b+1][0] + ((K & mask) ? score1 : score0);
    
    // dp[i+1][1] <= dp[i][0] : ����� Ki==1 �̏ꍇ�̂ݔ����BXi�͎����I�� 0 �ƌ��܂�
    //            <= dp[i][1] : Xi �� 0/1 �ǂ���ł������̂ŁAscore�̑傫����
    //  �A���A���Bit�������� K �ƈ�v�������̂����Ȃ������ꍇ�iK��MSB��������0�������ꍇ�Ȃǁj
    //  dp[b+1][1] ������Z����Ƃ����J�ڂ͑��݂��Ȃ�
    if ( dp[b+1][1] != -1 )
      dp[b][1] = dp[b+1][1] + max( score0, score1 );
    if ( K & mask )
      dp[b][1] = max( dp[b][1], dp[b+1][0] + score0 );
  }
//  REP(i,N+1)
//    cout << dp[i][0] << " ";
//  cout << endl;
//  REP(i,N+1)
//    cout << dp[i][1] << " ";
//  cout << endl;

  cout << max(dp[0][1], dp[0][0]) << endl;

}

