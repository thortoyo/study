#include <bits/stdc++.h>
using namespace std;

vector<string> field;
int seen[510][510];

int H,W;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs( int y, int x) {
  seen[y][x] = true;

  for( int i=0;i<4;++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    
    if ( (nx < 0) || (ny < 0) || (nx>=W) || (ny>=H) ) continue;
    if ( field[ny][nx] == '#') continue;
    if (seen[ny][nx] == true) continue;
    dfs(ny, nx);
  }
}


int main() {
  int sx,sy,ex,ey;
  
  cin >> H >> W;
  field.resize(H);

  for (int i=0;i<H;++i ) {
    cin >> field[i];
  }
  for (int y=0;y<H;++y ) {
    for (int x=0;x<W;++x ) {
      if ( field[y][x] == 's') {
        sx = x; sy = y;
      }
      if ( field[y][x] == 'g') {
        ex = x; ey = y;
      }
    }
  }
  memset( seen, 0, sizeof(seen) );
  dfs(sy,sx);
  if (seen[ey][ex] == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
