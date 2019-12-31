#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

vector<bool> IsPrime(110000,true);

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
  ll X;
  cin >> X;
  sieve(110000);
  int i = X;
  for ( ; !IsPrime[i]; ++i );
  cout << i << endl;
}
