#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
  int H,W;
  cin >> H >> W;
  vector< string > A(H);
  vector< vector<int> > d(H, vector<int>(W,-1));
  queue< pair<int,int> > q;
  REP(i,H) {
    cin >> A[i];
    REP(j,W) if (A[i][j] == '#') {
      q.emplace( i,j );
      d[i][j] = 0;
    }
  }
  int ans = 0;
  while ( !q.empty() ) {
    auto v = q.front(); q.pop();
    int y = v.first;
    int x = v.second;
    REP(i,4) {
      int ny = y+dy[i];
      int nx = x+dx[i];
      if ( (ny < 0) || (ny >=H) || (nx < 0) || (nx >= W)) continue;
      if ( d[ny][nx] != -1 ) continue;
      d[ny][nx] = d[y][x]+1;
      q.emplace( ny, nx );
      ans = max(d[ny][nx], ans);
    }
  }
  cout << ans << endl;
}
