#include <bits/stdc++.h>
using namespace std;

vector< queue<int> > A(1000);
set<int> done;

int main() {
  int64_t N;
  cin >> N;
  int64_t ans = 0;
  for( int i=0; i<N; ++i) {
    for( int j=0; j<N-1; ++j) {
      int ain;
      cin >> ain;
      A[i].emplace( --ain );
    }
  }

  int d = 0;
  while(1) {
//    cout << d << endl;
    int hit = 0;
    for(int i=0; i<N;i++ ) {
      if ( done.count(i) != 0 ) continue;
      if ( A[i].empty() ) continue;
      int tgt = A[i].front();
      if ( done.count(tgt) != 0 ) continue;
//      cout << i << " " << tgt << " " <<  A[tgt].front() <<endl;
      if( !A[tgt].empty() && A[tgt].front() == i ) {
//        cout <<  "  Hit" << endl;
        done.emplace(i);
        done.emplace(tgt);
//        for( auto aa: done ) cout << aa << ":" << endl;
        A[i].pop();
        A[tgt].pop();
        hit = 1;
      }
    }
    if ( hit == 0 ) {
      for( int i=0; i<N; ++i) {
        if ( !A[i].empty() ) {
          cout << "-1" << endl;
          return 0;
        }
      }
      break;
    }
    d++;
    done.clear();
  }

  cout << d << endl;

}
