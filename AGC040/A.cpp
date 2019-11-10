#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
/*
0	>	10	1
1	>>	210	3
2	>>>	3210	6

 0	<	01	1
 1	<<	012	3
 2	<<<	0123	6

 0	<>	010
 1	<<>	0120
 1	<<>>	01210
 1	<<>>>	013210
*/

const ll INF = 1LL << 60;

int main() {
  string S0,S;
  cin >> S0;

  int N = S0.length();
  if (S0[0] == '>') S = '<' + S0;
  else S = S0;
  if (S0[N-1] == '<') S += '>';
  S += '@';
//  cout << S0 << endl;;
//  cout << S << endl;;
  N = S.length();
  
  ll total = 0;
  ll l = 0;
  ll r = 0;
  REP(i,N-1) {
    if (S[i] == '<') {
      l++;
    } else {
      r++;
      if (S[i+1] != '>' ) {
//        cout << " " << l << " " << r << " : " << l * (l-1) / 2 << " " << r * (r-1) / 2 << " " << ((l > r)?l:r) << endl;
        total += l * (l-1) / 2;
        total += r * (r-1) / 2;
        if (l > r)
          total += l;
        else
          total += r;
        l = r = 0;
      }
    }
  }
  cout << total << endl;
  
}


    
    
