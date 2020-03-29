#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef int64_t ll ;

const ll MOD = 1000000007;

ll K,X,Y;
int xy[200010][2];

ll get_dist( ll x0,ll y0, ll x1, ll y1 ) {
  return( abs(x0-x1) + abs(y0-y1) );
}

int main() {
  cin >> K;
  cin >> X >> Y;
  // XとYは両方正の数にして扱いやすくする。
  int xinv = 1, yinv = 1;
  if ( X < 0 ) xinv = -1;
  if ( Y < 0 ) yinv = -1;
  X = X * xinv;
  Y = Y * yinv;

  ll cx=0, cy=0;

  // K偶数、距離奇数なら不可
  if ( (K%2==0) && ((get_dist(cx,cy,X,Y) % 2)==1) ) {
    cout << "-1" << endl;
    return 0;
  }

  int cnt = 0;
  // 2K未満になるまで近づく
  while( (get_dist(cx,cy,X,Y)) >= K * 2 ) {
    int dx,dy;
    dx = X-cx;
    if ( dx > K ) dx = K;
    dy = K - dx;
    cx += dx;
    cy += dy;
    xy[cnt][0] = cx;
    xy[cnt][1] = cy;
    cnt++;
  }
  
  int dist = get_dist(cx,cy,X,Y);
  if (dist == K) {
    // 丁度ゴールする場合
    xy[cnt][0] = X;
    xy[cnt][1] = Y;
    cnt++;
  } else {
    if (dist % 2 == 1 ) {
      // 距離奇数の場合
      //  距離偶数になるように一手動かす。K は必ず奇数なので、とりあえず動かせばOK
      //  ゴールを飛び越える場合もあるが、その時は Y 方向にのみ飛び出すはず。
      int dx,dy;
      dx = X-cx;
      if ( dx > K ) dx = K;
      dy = K - dx;
      cx += dx;
      cy += dy;
      xy[cnt][0] = cx;
      xy[cnt][1] = cy;
      cnt++;
      dist = get_dist(cx,cy,X,Y);
    }
    // 距離偶数の場合
    //  中点を求めて、そこから外側に残りを伸ばす。
    int dx,dy;
    int disth = dist / 2;
    dx = X-cx;
    if ( dx > disth ) dx = disth;
    dy = disth - dx;
    if ( cy > Y ) dy = -dy;
    cx += dx;
    cy += dy;
    if ( dy == 0 ) {
      // 　　　　　　　G
      //               │
      // S ────●─┘	● 中点
      //           │
      //           │
      //           ★ 		★ K-中点までの距離分だけ外に逃がした点
      cy -= (K - disth);
    } else {
      cx += (K - disth);
    }
    xy[cnt][0] = cx;
    xy[cnt][1] = cy;
    cnt++;
    xy[cnt][0] = X;
    xy[cnt][1] = Y;
    cnt++;
  }

  cout << cnt << endl;
  REP(i,cnt) {
    cout << xy[i][0]*xinv << " " << xy[i][1]*yinv << endl;
  }
  
}
