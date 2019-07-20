#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.second > secondElof.second;
}

int main() {
  int64_t N,M,Ain,B,C,min;
  vector< pair< int64_t,int64_t > > A;
  pair< int64_t,int64_t > apair;
  pair< int64_t,int64_t > bc;
  cin >> N >> M;
  min = 0;
  for (int i=0;i<N;i++ ) {
    cin >> Ain;
    apair.first = 1;
    apair.second = Ain;
    A.push_back(apair);
  }
//  for ( int64_t aa : A ) {
//	  cout << aa << " ";
//  }
//  cout << endl;
  for (int i=0; i<M; i++ ) {
    cin >> B >> C;
    apair.first = B;
    apair.second = C;
    A.push_back(apair);
  }
  sort(A.begin(),A.end(),pairCompare);

  vector<int64_t > ll;
  int tt = 0;

  for(int i=0;i<N;i++) {
    ll.push_back( A[tt].second );
    A[tt].first--;
    if (A[tt].first ==0) {
      tt++;
    }
  }
  int64_t cnt = 0;
  for ( int64_t aa : ll ) {
    cnt += aa;
  }
  cout << cnt << endl;
}
 