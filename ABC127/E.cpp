#include <bits/stdc++.h>
//#include <chrono>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

//#define DMY_IN

#define MOD 1000000007

// x^n ( mod M ) �����߂�
//  �Ⴆ�� n = 10 ���Ƃ����
//  x^10 = x^(2+8) = x^2 * x^8 = x^2 * ((x^2)^2)^2
//  10 = 'b1010
ll powmod( ll x, ll n) {
  ll ans = 1;
  while ( n > 0 ) {
    if (n & 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return ans;
}

// MOD�̋t��
//  a^(p-1) mod p = 1
//  a * a^(p-2) mod p = 1
//  a^(p-2) mod p = 1 / a mod p
ll inv( ll a ) {
  ll x = 1;
  for ( ll i=1; i<a+1; ++i ) {
    x = (i * x) % MOD;
  }
  return powmod( x, MOD-2 ) % MOD;
}

// n C r mod M
//  = n! / ( r! * (n-r)! )
//  = n * (n-1) * (n-2) * ... * (n-r+1) + (r!)^-1 
ll comb( ll n, ll r ) {
  ll ans = 1;
  for ( ll i=n; i>(n-r); --i ) {
    ans = (ans * i) % MOD;
  }
  return (ans * inv(r)) % MOD;
}

int main() {
  int N,M,K;
#ifdef DMY_IN
#else
  cin >> N >> M >> K;
#endif

//  std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
//  start = std::chrono::system_clock::now(); // �v���J�n����

  // 2�_���u�����ہA�c��̋��u�����@�̑g�ݍ��킹��
  // (N*M-2) C (K-2)
  ll c = comb( N*M-2, K-2 );
  
  ll ans = 0;

  // X����
  // �Q�_�Ԃ̋��� d
  ll tmpX = ((((N * N)) % MOD) * c ) % MOD;
  for (ll d=1; d<M; ++d ) {
    ans = (ans + (((tmpX * d) % MOD) * (M-d)) % MOD ) % MOD;
  }
//  cout << ans << " " << tmpX << " " << c << endl;
  
  // Y����
  ll tmpY = ((((M * M)) % MOD) * c ) % MOD;
  for (ll d=1; d<N; ++d ) {
    ans = (ans + (((tmpY * d) % MOD) * (N-d)) % MOD ) % MOD;
  }

  
  cout << ans << endl;

//  end = std::chrono::system_clock::now();  // �v���I������
//  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
//  std::cout << elapsed << " ms" << std::endl;
  
}


