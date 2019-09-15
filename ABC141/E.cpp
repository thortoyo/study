#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  string S;
//  cin >> N >> S;
  N = 5000;
  S += "abcdefghlj";
  REP(i,500)
    S += "abcdefghij";
  int cmax = 0;
  for( int cntm= N / 2; cntm >0; --cntm ) {
    for ( int i=cntm; i<N-cntm+1; ++i ) {
      int cnt = 0;
      for ( int j=0; j<N-cntm; ++j ) {
//        printf("%d %d %d %c %c\n",cntm, i, j, S[j], S[i+j] );
        if (S[j] == S[i+j]) {
          cnt++;
          if( cnt == cntm ) {
            cout << cntm << endl;
            return 0;
          }
        } else {
          cnt = 0;
        }
      }
    }
  }
  cout << "0" << endl;
}
