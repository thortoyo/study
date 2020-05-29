#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int d[500][500];
int s[500][500];
int mx[6] = {1,0,-1,1,-1,0};
int my[6] = {1,1,1,0,0,-1};
const int INF = 2000000000;

int main(){
  int N,X,Y;
  cin >> N >> X >> Y;
  X += 210; Y+= 210;
  REP(i,N) {
    int x , y;
    cin >> x >> y;
    x += 210; y+=210;
    s[x][y] = 1;
  }
  REP(i,500) REP(j,500) d[i][j] = INF;
  
  queue< pair<int,int> > q;
  q.push( {210,210} );
  d[210][210] = 0;
  while( !q.empty() ){
    auto v = q.front() ; q.pop();
    int x = v.first;
    int y = v.second;
    REP(i,6) {
      int nx = x+mx[i];
      int ny = y+my[i];
      if ( ( nx<0) || (nx>420) || (ny<0) || (ny> 420) ||
           (s[nx][ny] == 1) )
        continue;
      if ( d[nx][ny] <= d[x][y] + 1 ) continue;
      d[nx][ny] = d[x][y] + 1;
      q.push( {nx, ny} );
    }
  }
  if (d[X][Y] == INF) {
    cout << "-1" << endl;
  } else {
    cout << d[X][Y] << endl;
  }
}

