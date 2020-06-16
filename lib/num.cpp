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

// ëfêîîªíË
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

// ñÒêîóÒãì
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // èdï°ÇµÇ»Ç¢Ç»ÇÁÇŒ i ÇÃëäï˚Ç≈Ç†ÇÈ N/i Ç‡ push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // è¨Ç≥Ç¢èáÇ…ï¿Ç—ë÷Ç¶ÇÈ
    sort(res.begin(), res.end());
    return res;
}

// ëfàˆêîï™â
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // éwêî

        // äÑÇÍÇÈå¿ÇËäÑÇËë±ÇØÇÈ
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // ÇªÇÃåãâ Ç push
        res.push_back({a, ex});
    }

    // ç≈å„Ç…écÇ¡ÇΩêîÇ…Ç¬Ç¢Çƒ
    if (N != 1) res.push_back({N, 1});
    return res;
}
