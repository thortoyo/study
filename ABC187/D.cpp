#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  vector< pair<ll,ll> > AB(N);
  ll alla = 0;
  REP(i,N) {
    cin >> A[i] >> B[i];
    AB[i].first = 2 * A[i] + B[i];
    AB[i].second = A[i];
    alla += A[i];
  }
  sort(AB.begin(), AB.end());
  reverse(AB.begin(), AB.end());
  int ans = 0;
  ll su = 0;
//  cout << " : " << su << " " << alla << endl;
  REP(i,N) {
    su += (AB[i].first - AB[i].second);
    alla -= AB[i].second;
//    cout << AB[i].first << " " << AB[i].second << " : " << su << " " << alla << endl;
    if ( su > alla ) {
      ans = i+1;
      break;
    }
  }
  cout << ans << endl;
}
