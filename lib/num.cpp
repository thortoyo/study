ll GCD(ll a, ll b) {
  if ( a%b==0 ) return b;
  return GCD(b, a%b);
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// �f������
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

// �񐔗�
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // �d�����Ȃ��Ȃ�� i �̑����ł��� N/i �� push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // ���������ɕ��ёւ���
    sort(res.begin(), res.end());
    return res;
}

// �񐔂̌��𐔂���
ll count_divisors(long long N) {
    int ret = 0;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            ret++;
            // �d�����Ȃ��Ȃ�� i �̑����ł��� N/i �� push
            if (N/i != i) ret++;
        }
    }
    return ret;
}

// �f��������
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // �w��

        // �������芄�葱����
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // ���̌��ʂ� push
        res.push_back({a, ex});
    }

    // �Ō�Ɏc�������ɂ���
    if (N != 1) res.push_back({N, 1});
    return res;
}

// �G���g�X�e�l�X���
vector<bool> isp(N+1, true);
void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; i*i<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}


// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
 