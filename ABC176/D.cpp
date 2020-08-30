#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int d[1010][1010];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

const int INF = 1000000000;

int main(){
  int H,W;
  cin >> H >> W;
  int CH,CW, DH,DW;
  cin >> CH >> CW >> DH >> DW;
  CH--; CW--; DH--; DW--;
  vector< string > s(H);
  REP(i,H) cin >> s[i];

  REP(y,H) REP(x,W) d[y][x] = INF;
  d[CH][CW] = 0;

  queue< pair<int, int> > q, nq;
  nq.emplace( CH, CW );

  int step = 0;
  while(1) {
    if ( nq.empty() ) break;
    swap(q, nq);

    // BFS
    while( !q.empty() ) {
      auto v = q.front(); q.pop();
      int h = v.first;
      int w = v.second;
      // 5x5ÇÃîÕàÕÇÇµÇƒnextÉLÉÖÅ[Ç…
      for(int iy=-2; iy<=2; iy++ )
        for(int ix=-2; ix<=2; ix++ ) {
          if (iy==0 && ix==0) continue;
          if (abs(iy)==1 && ix==0) continue;
          if (abs(ix)==1 && iy==0) continue;
          int ny = h + iy;
          int nx = w + ix;
          if ((nx < 0) || (nx >=W) || (ny < 0) || (ny >=H) ) continue;
          if ( (s[ny][nx] == '.') && (d[ny][nx] > d[h][w]+1)) {
            d[ny][nx] = d[h][w]+1;
            nq.emplace( ny, nx );
          }
        }
      // ïÅí Ç…4ï˚å¸Ç…BFS
      REP(i,4) {
        int ny = h + dy[i];
        int nx = w + dx[i];
        if ((nx < 0) || (nx >=W) || (ny < 0) || (ny >=H) ) continue;
        if ( (s[ny][nx] == '.') && (d[ny][nx] > d[h][w])) {
          d[ny][nx] = d[h][w];
          q.emplace(ny, nx);
        }
      }
    }

//    REP(y,4) {
//      REP(x,4) cout << d[y][x] << " ";
//      cout << endl;
//    }
  }

  if ( d[DH][DW] == INF ) d[DH][DW] = -1;
  cout << d[DH][DW] << endl;
}
