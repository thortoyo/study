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

// ����v�Z
long long PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
}

int main() {
  // �O����
  COMinit();
  COM(10,5);	// 10 C 5
}


// �p�X�J���̎O�p�`�ɂ��񍀌W��(nCk)�̌v�Z
/*
    �O����: O(MAX_N*MAX_N)
    nCk(n,k): nCk �̌v�Z�BO(1)
*/
const int MAX_N = 50;         // n �̍ő�l
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

int main() {
    long long n, k;
    cin >> n >> k;
    init();
    cout << nCk(n, k) << endl;
}