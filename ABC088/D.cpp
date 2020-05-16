#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int len[60][60];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

int main() {
  int H,W;
  vector< string > s;
  cin >> H >> W;

  s.push_back( string( W+2, '#' ));
  int wn = 0;
  REP(i,H) {
    string ss;
    cin >> ss;
    ss = "#" + ss +"#";
    REP(j,W+2) if ( ss[j] == '.' ) wn++;
    s.push_back( ss );
  }
  s.push_back( string( W+2, '#' ) );
  REP(i,60) REP(j,60) len[i][j] = 100*100;
  len[1][1] = 0;

  queue<pair<int,int> > q;
  q.push( { 1, 1 } );
  while( !q.empty() ) {
    auto v = q.front(); q.pop();
    int y = v.first;
    int x = v.second;
    REP(i,4) {
      int ny = y+dy[i];
      int nx = x+dx[i];
      if ( s[ny][nx] == '.' && len[ny][nx] > len[y][x]+1 ) {
        len[ny][nx] = len[y][x] + 1;
        q.push({ ny, nx });
      }
    }
  }
  if (len[H][W] == 100*100) {
    cout << "-1" << endl;
  } else {
    cout << (wn - (len[H][W]+1)) << endl;
  }
}

