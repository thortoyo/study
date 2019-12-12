#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;


bool dp[85][85][13000];

int main() {
  int H,W;
  cin >> H >> W;
  vector< vector< int > > A(82, vector<int>(82,0));
  vector< vector< int > > A1(82, vector<int>(82,0));
  vector< vector< int > > A2(82, vector<int>(82,0));
  vector< vector< int > > B(82, vector<int>(82,0));
  for (int y=1; y<H+1; ++y ) 
    for (int x=1; x<W+1; ++x ) 
      cin >> A[x][y];
  for (int y=1; y<H+1; ++y ) 
    for (int x=1; x<W+1; ++x ) 
      cin >> B[x][y];
  for (int y=1; y<H+1; ++y ) 
    for (int x=1; x<W+1; ++x ) {
      A1[x][y] = A[x][y] - B[x][y] + 80;
      A2[x][y] = B[x][y] - A[x][y] + 80;
    }

  dp[0][1][0] = true;
  for (int y=1; y<H+1; ++y ) 
    for (int x=1; x<W+1; ++x ) 
      for (int num=0; num<13000; ++num ) {
        if ( num - A1[x][y] >= 0 ) 
          dp[x][y][num] |= dp[x-1][y][num-A1[x][y]] | dp[x][y-1][num-A1[x][y]];
        if ( num - A2[x][y] >= 0 ) 
          dp[x][y][num] |= dp[x-1][y][num-A2[x][y]] | dp[x][y-1][num-A2[x][y]];
      }

  int num;
  for (num=0; num<13000/2; ++num ) {
    if ( dp[W][H][ 80*(H+W-1) + num ] ) break;
    if ( dp[W][H][ 80*(H+W-1) - num ] ) break;
  }
  cout << num << endl;

//  for (int y=1; y<H+1; ++y ) 
//    for (int x=1; x<W+1; ++x ) {
//      cout << "--- " << x << ", " << y << endl << " ";
//      for ( num=0; num<13000; ++num )
//        if ( dp[x][y][num] ) cout << num << " ";
//      cout << endl;
//    }

  return 0;
}
