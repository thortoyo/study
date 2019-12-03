#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// �ő����
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

// �f���������Ń��j�[�N�Ȍ��𐔂���
int prime_fact(ll a) {
  int cnt = 0;
  int prei = 0;
  ll sa = sqrt(a)+1;
  for (ll i=2;i<=sa;++i ) {
    while (a%i==0) {
      if (prei != i) cnt++;
      prei = i;
      a /= i;
//      cout << i << " " << a << endl;
    }
  }
  return cnt;
}

// n �̖񐔂��
vector<ll> enum_div(ll n) {
  vector<ll> ret;
  ll sn = sqrt(n);
  for(ll i=1 ; i<=sn ; ++i) {
    if(n%i == 0) {
      ret.push_back(i);
      if(i!=(n/i) && i*i!=n)
        ret.push_back(n/i);
    }
  }
  return ret;
}

vector<bool> IsPrime;

void sieve(ll max){
  if(max+1 > IsPrime.size()){     // resize�ŗv�f��������Ȃ��悤��
    IsPrime.resize(max+1,true); // IsPrime�ɕK�v�ȗv�f�����m��
  } 
  IsPrime[0] = false; // 0�͑f���ł͂Ȃ�
  IsPrime[1] = false; // 1�͑f���ł͂Ȃ�

  ll smax = sqrt(max);
  for(ll i=2; i<=smax; ++i) // 0����sqrt(max)�܂Œ��ׂ�
    if(IsPrime[i]) // i���f���Ȃ��
      for(ll j=2; i*j<=max; ++j) // (max�ȉ���)i�̔{����
        IsPrime[i*j] = false;      // �f���ł͂Ȃ�
}

int main() {
  ll A,B;
  cin >> A >> B;

  if ( A < B ) swap(A,B);
  ll g = gcd(A,B);
//  cout << g << endl;
//  vector<ll> gv = enum_div(g);
//  for ( auto x: gv ) cout << x << " ";
//  cout << endl;
//  ll gvsize = gv.size();

//  sieve(g);

//  ll cnt = 0;
//  REP(i,gvsize) {
//    if ( IsPrime[gv[i]] ) cnt++;
//  }
  int cnt = prime_fact(g);
  cout << cnt+1 << endl;
}
