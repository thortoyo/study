#include <bits/stdc++.h>
using namespace std;
// aa
// a aa
// a aa a

// b a
// b aa
// b a aa
// b a aa a

// aa
// a ab
// a ab b


int main() {
  string S;
  cin >> S;

  int l = S.length();

  bool pre2 = false;
  int ans = 0;
  for (int i=1;i<l;++i ) {
    if (pre2 || (S[i] != S[i-1])) {
      ans++;
      pre2 = false;
    } else {
      pre2 = true;
    }
  }
  cout << ans << endl;
}

