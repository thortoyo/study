#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main(){
  int N;
  cin >> N;
  vector<ll> A(N+4,0);
  vector<ll> AE(N+4,0);
  vector<ll> AO(N+4,0);
  REP(i,N) cin >> A[i];
  AE[0] = A[0];
  AE[1] = A[0];
  AO[0] = 0;
  AO[1] = A[1];
  for (int i=2; i<N; i++ ) {
    AE[i] = AE[i-1];
    AO[i] = AO[i-1];
    if ( i%2 == 0 ) AE[i] += A[i];
    else  AO[i] += A[i];
  }

  REP(i,N) cout << " " << AE[i];
  cout << endl;
  REP(i,N) cout << " " << AO[i];
  cout << endl;

  ll ans = -30000000000000000;
  ll tmp = 0;
  if ( N%2==0 ) {
    ans = max(AE[N-1], AO[N-1]);
  } else {
    // S[i]�����O�����ꍇ
    int l = 0;
    int r = N-1;
    int rem = N/2;
    REP(i,rem/2) {
      if ( rem == 0 ) {
        ans = max( ans, tmp );
        break;
      } else if ( rem == 1 ) {
        ll t = max(A[l] , max(A[l+1], A[r]) );
        ans = max( ans, tmp+t );
        break;
      }
      // ���[��I�����Ȃ��ꍇ
      ans = max( ans, tmp + AE[r] - AE[l]);
      ans = max( ans, tmp + AO[r] - AO[l]);
      // �E�[��I�����Ȃ��ꍇ
      ans = max( ans, tmp + AE[r-1]- ((l==0) ? 0 : AE[l-1]));
      ans = max( ans, tmp + AO[r-1]- ((l==0) ? 0 : AO[l-1]));
      // �����I������ꍇ
      tmp += A[r] + A[l];
      rem -= 2;
      l += 2;
      r -= 2;
    }
  }
  cout << ans << endl;
}
