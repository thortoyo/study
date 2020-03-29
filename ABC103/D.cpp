#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> T;
  vector< pair<int,int> > A(M),B(M);
  REP(i,M)  {
    cin >> A[i].first >> B[i].first;
    A[i].second = i;
    B[i].second = i;
    T.emplace_back(A[i].first);
    T.emplace_back(B[i].first);
  }
  sort(T.begin(),T.end());
  REP(i,M) {
    A[i].first = distance(T.begin(), lower_bound(T.begin(),T.end(),A[i].first));
    B[i].first = distance(T.begin(), lower_bound(T.begin(),T.end(),B[i].first));
    cout << "A " << A[i].first << " " << A[i].second << endl;
    cout << "B " << B[i].first << " " << B[i].second << endl;
  }

}
  
