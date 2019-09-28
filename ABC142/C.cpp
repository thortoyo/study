#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N;
  cin >> N;
  vector< pair<int,int> > A(N);
  REP(i,N) {
    cin >> A[i].first;
    A[i].second = i+1;
  }
  sort( A.begin(), A.end() );
  
  REP(i,N) {
    cout << A[i].second << " ";
  }
  cout << endl;
}
