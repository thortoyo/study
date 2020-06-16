#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;



int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  map<int,int> M;
  REP(i,N) {
    cin >> A[i];
    M[A[i]]++;
  }
  int ans = 0;
  REP(i,N) {
    M[A[i]]--;
    int find = 0;
    for (int j = 1; j*j<=A[i]; ++j) {
      if (A[i]%j==0) {
        if (M[j]!=0) {
          find = 1; 
          break;
        }
        if (A[i]/j!=j)
          if (M[A[i]/j]!=0) {
            find = 1;
            break;
          }
      }
    }
    if (find == 0) {
      ans++;
    }
    M[A[i]]++;
  }
  cout << ans << endl;
}
