#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  if (K>=N) {
    cout << N << endl;
    return 0;
  }

  vector<int> C,R;
  R.push_back(0);
  if (S[0]=='0' ) C.push_back(0);
  S = S + 'Z';
  int cnt = 1;
  REP(i,N){
    if ( S[i] != S[i+1] ) {
      C.push_back(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if (S[N-1]=='0' ) C.push_back(0);
  
  REP(i, C.size())
    R.push_back( R[i]+C[i] );

  int smax = 0;
  for ( int l=0; (2*l)<R.size(); ++l ) {
    int ridx = min(2*(l+K-1)+3, (int)R.size()-1);
    smax = max( smax, R[ridx] - R[2*l] );
//    cout << "- [" << l << "," << (2*(l+K-1)+3) << "] " << R[2*(l+K-1)+3] << " - " << R[2*l] << endl;
  }
//  REP(i,R.size())
//    cout << C[i] << " " << R[i] <<endl;
  cout << smax << endl;
}
