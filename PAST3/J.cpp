#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll k[100005];

int main(){
  int N,M;
  cin >> N >> M;

  vector<int> k(N,0);

  REP(i,M) {
    int a;
    cin >> a;
    a = -a;
    auto it = upper_bound( k.begin(), k.end(), a );
    if ( it != k.end() ) {
      *it = a;
      cout << (distance( k.begin(), it )+1) << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}

