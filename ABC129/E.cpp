#include <bits/stdc++.h>
using namespace std;

string L;
int64_t sum_u = 2;
int64_t sum_l = 1;
int64_t md = 1000000007;
int main() {
  cin >> L;
  for (int i=1;i<L.length();i++ ) {
    if( L[i] == '1' ) {
      sum_l = (sum_l * 3 + sum_u) % md;
      sum_u = (sum_u * 2) % md;
    } else {
      sum_l = (sum_l * 3) % md;
    }
  }
  cout << (sum_l+sum_u)%md << endl;
}

