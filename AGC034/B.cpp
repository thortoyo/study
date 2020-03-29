#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, ns;
  cin >> S;
  int ng = 0;
  int prex = 0;
  size_t slen = S.length();
  for(int i=0;i<slen-1;++i) {
    if (S[i]=='A') {
      ns.push_back('A');
      prex = 0;
    } else if ((S[i] == 'B') && (S[i+1] == 'C')){
      ns.push_back('D');
      ++i;
      prex = 0;
    } else {
//      if (prex == 0) {
        ns.push_back('X');
        prex = 1;
//      }
    }
  }
//  cout << ns << endl;
  size_t nslen = ns.length();
  int dcnt = 0;
  int64_t t=0;
  for(int i=nslen-1;i>=0;--i) {
    if( ns[i]=='D') {
      ++dcnt;
    } else if (ns[i] == 'A') {
      t += dcnt;
    } else if (ns[i] == 'X') {
      dcnt=0;
    }
  }
  cout << t << endl;
      

    
  return 0;
}
  
