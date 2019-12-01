#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int X;
  cin >> X;
  int a = X%100;
  int b = a/5 + ((a%5==0) ? 0:1);
  int c=X/100;
//  cout << a << " " << b << " " << c << endl;
  if (c>=b)
    cout << "1" << endl;
  else
    cout << "0" << endl;

}
