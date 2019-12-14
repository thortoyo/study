#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  vector<ll> s(3);
  s[0] = 3;
  s[1] = 4;
  s[2] = 8;
  auto it1 = lower_bound( s.begin(), s.end(), 1 );	// 3
  auto it3 = lower_bound( s.begin(), s.end(), 3 );	// 3
  auto it4 = lower_bound( s.begin(), s.end(), 4 );	// 4
  auto it7 = lower_bound( s.begin(), s.end(), 7 );	// 8
  auto it8 = lower_bound( s.begin(), s.end(), 8 );	// 8
  auto it9 = lower_bound( s.begin(), s.end(), 9 );	// end()
  cout << *it1 << endl;
  cout << *it3 << endl;
  cout << *it4 << endl;
  cout << *it7 << endl;
  cout << *it8 << endl;
  cout << *it9 << endl;
  it1 = upper_bound( s.begin(), s.end(), 1 );	// 3
  it3 = upper_bound( s.begin(), s.end(), 3 );	// 4
  it4 = upper_bound( s.begin(), s.end(), 4 );	// 8
  it7 = upper_bound( s.begin(), s.end(), 7 );	// 8
  it8 = upper_bound( s.begin(), s.end(), 8 );	// end()
  it9 = upper_bound( s.begin(), s.end(), 9 );	// end()
  cout << *it1 << endl;
  cout << *it3 << endl;
  cout << *it4 << endl;
  cout << *it7 << endl;
  cout << *it8 << endl;
  cout << *it9 << endl;

  return 0;
}
