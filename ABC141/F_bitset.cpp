#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  ll ans = 0;
  cin >> N;
  vector<ll> A(N);
  vector< bitset<100010> > B(60, bitset<100010>(0));
  ll all_a = 0;
  REP(i, N) {
    ll ain;
    cin >> A[i];
    all_a ^= A[i];
  }
  // �S��XOR��������l�ŁA1 �ɂȂ���bit�͂ǂ̂悤�ȕ����������Ă��A�Е��͋����A�����Е��͊�ɂȂ�̂ŁA
  // ����bit�͍l�����Ȃ���OK�B
  // �ŏI�I�ɘa�����߂�ۂɁA����bit�� 0+1 �� 1+0 �ɂ����Ȃ�Ȃ��̂ŁA�a�� 1 �ɂȂ�B
  // �܂�A���� all_a ���̂��̂𑫂��΂����B
  // 0 �ɂȂ��� bit �� �����Ƌ����A��Ɗ �̂ǂ��炩�ɂȂ�B
  // ���R�A��{��ɂȂ����ق����a�͑傫���̂ŁA�����ڎw���B

  // �l�����Ȃ�bit�̏�������
  REP(i,N) A[i] &= ~all_a;

  // �l�����Ȃ����̘a�� 1 �ɂȂ�̂ŁA��ɑ����Ă���
  ans = all_a;
  
  // �|���o���@���g����悤��
  //  B[0] = [ A[0].bit59, A[1].bit59,,, A[N-1].bit59, 1 ] 
  //  B[1] = [ A[0].bit58, A[1].bit58,,, A[N-1].bit58, 1 ] 
  // �Ƃ���2�����z��Ɋi�[
  REP(i,60) {
    REP(j,N) {
      B[59-i][j] = (A[j] >> i) & 1;
    }
    B[59-i][N] = 1;
  }
  
  // �|���o���@
  //  �������A�ł��邾�����Bit��1�ɂȂ���������̂ŁA��ʑ�����D�悵�Ĕ��肷��
  //  ��L�ōl�����Ȃ�bit�ɂ������́A�Ή�����s�̒l���S�� 0 �ɂȂ��Ă���B
  //  ���̂��߁Apivot�ɑI�΂�邱�Ƃ͂Ȃ����A0 �Ȃ̂� xor ���Z�̑ΏۂɂȂ邱�Ƃ��Ȃ��B
  //  �Ȃ̂ŁA�Ō�܂œ����` (0 0 0...0 | 1) �����Ă���͂�
  vector<bool> use(60,false);
  REP(col,N) {
    int pivot = -1;
    // Pivot�T��
    REP(row,60) {
      if (use[row]) continue;
      if (B[row][col] == 1) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    
    // ��������pivot�ȊO�̍s�́A���݂̗�̒l�� 0 �ɂ��Ă���
    REP(row,60) {
      if ((row != pivot) && (B[row][col] == 1)) {
        B[row] ^= B[pivot];
      }
    }
    use[pivot] = true;
  }

  
  // (0 0 0 0 | 1) �ƂȂ��Ă��錅�͖���
  REP(row,60) {
    bool ok = false;
    if ( (B[row][N] == 0) ) ok = true;
    REP(col,N)
      if ( B[row][col] == 1 ) ok = true;
    // 2�O���[�v�̂ǂ���� 1 �ɂȂ�̂ŁA���v�l�͂��̌��� 2 �ɂȂ������̂ɂȂ�
    if (ok) 
      ans += (2LL << (59-row));
  }

  cout << ans << endl;
}
