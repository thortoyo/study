#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  ll ans = 0;
  ll t = 0;
  vector<ll> a(N+1);
  vector<ll> kmin(N+2);
  vector<ll> kmax(N+2);
  REP(i,N+1) cin >> a[i];

  kmin[0] = 1;
  kmax[0] = 1;
  kmin[N+1] = 0;
  kmax[N+1] = 0;
  // �����珇�ɁA�[��i �ɂ��肤�钸�_���̍ő�ƍŏ������߂�
  for (int i=N; i>=0; i--) {
    kmin[i] = a[i] + (kmin[i+1]+1)/2;
    kmax[i] = a[i] + kmax[i+1];
//    cout << i << " : " << kmin[i] << " " << kmax[i] << endl;
  }
  
  // �ォ�珇�ɁA�[��i �ɂ��肤�钸�_���̍ő�ƍŏ������߂�
  // ��قǉ����珇�ŋ��߂Ă������ő�ŏ��Ɣ�r���A�͈͂��i��
  bool ng = false;
  if ((kmin[0] > 1) || (kmax[0] < 1)) {
    cout << "-1" << endl;
    return 0;
  } else if ( N != 0 ) {
    kmin[0] = 1;
    kmax[0] = 1;
    for (int i=1; i<=N; i++) {
      ll cmax = (kmax[i-1] - a[i-1]) * 2;
      ll cmin = kmin[i-1] - a[i-1];
//      cout << i << " : " << kmin[i] << " " << kmax[i] << endl;
//      cout <<  "  : " << cmin << " " << cmax << endl;
      if ( (cmax < kmin[i]) || (cmin > kmax[i]) ) {
        cout << "-1" << endl;
        ng = true;
        return 0;
      }
      kmax[i] = min(kmax[i], cmax);
      kmin[i] = max(kmin[i], cmin);
    }
  }
//  REP(i,N+1)
//    cout << i << " : " << kmin[i] << " " << kmax[i] << endl;
  REP(i,N+1) {
    ans += kmax[i];
  }
  cout << ans << endl;
}


