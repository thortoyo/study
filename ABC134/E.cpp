#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll ;

const ll MOD = 1000000007;

int main() {
  int N;
  multiset<int> S;

  cin >> N;
  for (int i=0;i<N;i++)  {
    int a;
    cin >> a;
    auto it = S.lower_bound(a);
    if ( it != S.begin() ) {
//      cout << " Erase " << *(--it)<< endl; ++it;
      S.erase(--it);
    }
    S.insert(a);
  }

  cout << S.size() << endl;
  
}
