#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

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

int main(){
  ll N,P;
  cin >> N >> P;
  auto pf = prime_factorize(P);
  ll ans = 1;
  for ( auto p : pf) {
//    cout << " " << p.first << " " << p.second << endl;
    REP(i, p.second/N ) ans *= p.first;
  }
  cout << ans << endl;
}
  