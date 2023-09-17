#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


void solve() {
  int Q;
  cin >> Q;
  list<int> al;
  priority_queue<int, vector<int>, greater<int> > sl;
  REP(i,Q) {
    int c, x, o;
    cin >> c;
    if (c==1) {
      cin >> x;
      al.push_back(x);
    } else if (c==2) {
      if (sl.empty()) {
        o = *(al.cbegin());
        al.pop_front();
      } else {
        o = sl.top();
        sl.pop();
      }
      cout << o << endl;
    } else {
      while( !al.empty() ) {
        sl.push( al.front() );
        al.pop_front();
      }
    }
//    cout << " - ";
//    for( auto a: al ) cout << a << " ";
//    cout << endl;
  }

  return;
}

int main(){
  solve();
}


