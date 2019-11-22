// �R���r�l�[�V����
//  10^6 ���炢�܂ł�����炵��
//  �_���͂܂������o���ĂȂ��B�B�B

const ll MAX = 1000000;
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

int main() {
  // �O����
  COMinit();
  COM(10,5);	// 10 C 5
}

  
