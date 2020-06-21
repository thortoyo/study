#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int all = 0;
  REP(i,N) {
    cin >> A[i];
    all ^= A[i];
  }
  REP(i,N) {
    cout << (all ^ A[i]) << " ";
  }
  cout << endl;

}
