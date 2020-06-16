#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N,M;
  cin >> N;
  vector< queue<int> > K(N);
  vector< vector<int> > K01(N, vector<int>(2) );
  map< int, int, greater<int> >  m0,m1;
  
  REP(i,N) {
    int k;
    cin >> k;
    REP(j,k) {
      int a;
      cin >> a;
      K[i].push(a);
      if ( j==0 ) m0[a] = i, K01[i][0] = a, K[i].pop();
      if ( j==1 ) m1[a] = i, K01[i][1] = a, K[i].pop();
    }
  }
  cin >> M;
  for( auto m: m0 )
    cout << "0: " << m.first << " " << m.second << endl;
  for( auto m: m1 )
    cout << "1: " << m.first << " " << m.second << endl;
  REP(i,M) {
    int a;
    cin >> a;
    int mp0,mp1,mn0,mn1;
    mn0 = (*(m0.begin())).first;
    mp0 = (*(m0.begin())).second;
    mn1 = (*(m1.begin())).first;
    mp1 = (*(m1.begin())).second;
    if ( a==1 || ((a==2) && (mn0 >= mn1)) ) {
      cout << mn0 << endl;
      m0.erace( m0.begin() );
      m0[ K01[ mp0 ][1] ] = mp0;
      m1.erace( K01[ mp0 ][1] );
      m1[ K[i].front() ] = mp0;
      K[i].pop();
    } else {
      cout << mn1 << endl;
      m1.erace( m1.begin() );
      m0[ K01[ mp0 ][1] ] = mp0;
      m1.erace( K01[ mp0 ][1] );
      m1[ K[i].front() ] = i;
      K[i].pop();
      
      K[rpos]
    pair<int,int> smam({0,0});
    if (a==1) smax = *(s1.begin());
    else  smax = *(s0.begin());
    cout << smax.first << endl;
    rpos = smax.second;
    if (a==0) s0.erace(s0.begin());
    else  s1.erace(s1.begin());
    
    s0m.erace( s0.begin() );
      
      if (!K[rpos].empty()) {
      
    }
      
//    auto s0 = *(s[0].begin());
//    cout << "0: " << s0.first << " " << s0.second << endl;
//    cout << "1: " << s1.first << " " << s1.second << endl;
  }
}
