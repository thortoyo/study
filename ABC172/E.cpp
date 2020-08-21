#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll MAX = 2000000;
const ll MOD = 1000000007;

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

// ����v�Z
long long PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
}

int main(){
  ll N,M;
  cin >> N >> M;
  COMinit();

  // A = 1,2,3,..,N �ɌŒ肵�čl����
  // B �̑g�ݍ��킹���͉����������Ȃ��Ȃ� PER(M, N)
  // ���Ȃ��Ƃ� i �� A �� B ����v���Ă���ꍇ�́APER(M-i, N-i)
  // i �̈�v������ꍇ�̑g�ݍ��킹�� COM(M, i)
  // ������� i ��͈����A�����͑���
  //  i=0 �̏ꍇ�́A�S�����s��Ȃ̂őS���ۂ̐��ɂȂ�̂� �{ 
  //  i=1 �̏ꍇ����L�S���ۂ�������̂�  �[
  // �Œ肵�Ă��� A �̑g�ݍ��킹���� PER(M ,N)
  ll ans = 0;
  for( ll i=0; i<=N; i++ ) {
    ll c = PER(M-i, N-i);
    c = c * COM(N, i) % MOD;
    if ( i&1 == 1 ) c = -c;
    ans = (ans + c) % MOD;
    if ( ans < 0 ) ans += MOD;
//    cout << i << " : " << ans << endl;
  }
  ans = ans * PER(M,N) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
