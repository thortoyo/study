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
  // X��Y�͗������̐��ɂ��Ĉ����₷������B
  int xinv = 1, yinv = 1;
  if ( X < 0 ) xinv = -1;
  if ( Y < 0 ) yinv = -1;
  X = X * xinv;
  Y = Y * yinv;

  ll cx=0, cy=0;

  // K�����A������Ȃ�s��
  if ( (K%2==0) && ((get_dist(cx,cy,X,Y) % 2)==1) ) {
    cout << "-1" << endl;
    return 0;
  }

  int cnt = 0;
  // 2K�����ɂȂ�܂ŋ߂Â�
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
    // ���x�S�[������ꍇ
    xy[cnt][0] = X;
    xy[cnt][1] = Y;
    cnt++;
  } else {
    if (dist % 2 == 1 ) {
      // ������̏ꍇ
      //  ���������ɂȂ�悤�Ɉ�蓮�����BK �͕K����Ȃ̂ŁA�Ƃ肠������������OK
      //  �S�[�����щz����ꍇ�����邪�A���̎��� Y �����ɂ̂ݔ�яo���͂��B
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
    // ���������̏ꍇ
    //  ���_�����߂āA��������O���Ɏc���L�΂��B
    int dx,dy;
    int disth = dist / 2;
    dx = X-cx;
    if ( dx > disth ) dx = disth;
    dy = disth - dx;
    if ( cy > Y ) dy = -dy;
    cx += dx;
    cy += dy;
    if ( dy == 0 ) {
      // �@�@�@�@�@�@�@G
      //               ��
      // S ��������������	�� ���_
      //           ��
      //           ��
      //           �� 		�� K-���_�܂ł̋����������O�ɓ��������_
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
