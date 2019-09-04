#include <bits/stdc++.h>
using namespace std;

vector< queue<int> > A(1000);
set<int> q, q2;

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
    q.emplace(i);
  }

  int M = N * (N-1) / 2;
  int d = 0;
  while( !q.empty() ) {
//    cout << d << endl;
    int hit = 0;
//    cout << "- "; for( auto i: q ) cout << i << " "; cout << endl;

    while( !q.empty() ) {
      int i = *( q.begin() );
//      cout << i << ":";
      q.erase(i);
//      cout << "-- "; for( auto i: q ) cout << i << " "; cout << endl;
      int tgt = A[i].front();
//      cout << tgt << " " <<  A[tgt].front() <<endl;
      if( !A[tgt].empty() && A[tgt].front() == i && (q2.count(tgt)==0)) {
//        cout <<  "  Hit" << endl;
        A[i].pop();
        A[tgt].pop();
        q.erase(tgt);
//        cout << "-- "; for( auto i: q ) cout << i << " "; cout << endl;
        if ( !A[i].empty() ) q2.emplace(i);
        if ( !A[tgt].empty() ) q2.emplace(tgt);
//        for( auto aa: q2 ) cout << aa << ":" << endl;
        M--;
      }
    }
    d++;
    if ( M==0) break;
    q.clear();
    swap(q,q2);
    q2.clear();
  }
  if (M) d = -1;

  cout << d << endl;

}
