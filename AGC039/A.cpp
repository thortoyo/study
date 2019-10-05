#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll K;
  string S;
  cin >> S >> K;
  int slen = S.length();
  vector<int> r;
  int t = 1;
  int first = 0;
  int last = 0;
  bool all_same = true;
  REP(i,slen-1) {
    if (S[i] == S[i+1]) {
      t++;
      if ( i == 0 ) first = 1;
      if ( i == slen-2 ) {
        last = t;
      }
    } else {
      all_same = false;
      if (t != 1) {
        if (first==1) first = t;
        else r.push_back(t);
      }
      t = 1;
    }
  }
  if (S[0] == S[slen-1]) {
    if (first==0) first = 1;
    if (last==0) last = 1;
  } else {
    r.push_back(first);
    r.push_back(last);
    first = 0;
    last = 0;
  }
//  cout << first << " " << last << endl;
//  for(auto x:r) cout << x << " "; cout << endl;
  ll mid = 0;
  for(auto x:r) mid += x/2;
  ll ans = 0;
  if (K==1) {
    ans = first/2 + last/2 + mid;
  } else if (K==2) {
    ans = first/2 + last/2 + mid * 2 + (first+last) / 2;
  } else {
    ans = ((first+last) / 2) * (K-1);
    ans += mid * (K-2);
    ans += first/2 + last/2 + mid * 2;
  }
  if ( all_same ) ans = (last * K) / 2;
  cout << ans << endl;
}
