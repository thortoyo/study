#include <iostream>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// �P���ɔ͈͓��̊e���W�� C �𑫂��̂� 10^6�܂Ŕ͈͂�����̂ŁA 10^12 �őS��������NG
// �H�v���Čv�Z�ʂ�}����K�v������B
// ������W�ł̌o�H������ f(x,y) �Ƃ����
// 	f(a+1,b) = f(a,0) + f(a,1) +  f(a,2) + ... + f(a,b)
// �炵���B
// 	3  ���Z �� (a+1, 3)
// 	2  ����
// 	1  ����
// 	0  ����
// 	  a  a+1
// �ƂȂ�ƁA(a+1, 4) �ɍs���o�H�� (a,0),(a,1),(a,2),(a,3) �̍��v�ɂȂ�B
// �Ƃ������Ƃ͋��߂钷���`�ɏ�ӂ̊e�l���v�Z������A���̈���̗�̏c�S�������Z�����l���킩��B
// ���߂钷���`�̉��ӂ̈���̊e�l���v�Z���Ĉ����Ă��ƁA�����`�̒��g�̍��v���킩��B
// ��ӂ̊e�l�̉��Z���A��L��x��y�Ƃ��t�ɂȂ����łƍl���邱�Ƃ��ł��āA
// ��ӂ̉E�[+1 �܂ł̍��v�l�́A��ӂ̉E�[+1������Ɉ��ɍs�������W�̒l�ɂȂ�B
// ����Ĕ͈͂� �� r1 �` r2�A�c c1 �` c2 �Ȃ̂ŁA
// 	f(r2+1, c2+1) - f(r1, c2+1) - f(r2+1, c1) + f(r1+1,c1+1)
// �Ōv�Z�ł���B

const int MAX = 2000005;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// �e�[�u�������O����
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// �񍀌W���v�Z
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  // �O����
  COMinit();

  ll r1,r2,c1,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  // f(r2+1, c2+1) - f(r1, c2+1) - f(r2+1, c1) + f(r1+1,c1+1)
  ll ans = (COM( r2+1+c2+1, c2+1 ) + COM( r1+c1, c1 )) % MOD;
  ans -= COM( r1+c2+1, c2+1 );
  ans = (ans<0) ? ans + MOD : ans;
  ans -= COM( r2+1+c1, c1 );
  ans = (ans<0) ? ans + MOD : ans;
  cout << ans << endl;
}

