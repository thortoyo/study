#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,A,B;
  pair <int,int> ab;
  set< pair <int,int> >  S;
  cin >> N;
//  N = 2;
  for (int i=0; i<N; i++ ) {
    cin >> A >> B;
//    A = 1;B=2;
    if (A>B) {
      ab.first = A;
      ab.second = B;
    } else {
      ab.first = B;
      ab.second = A;
    }
    S.insert(ab);
  }
  cout << S.size() << endl;
}


