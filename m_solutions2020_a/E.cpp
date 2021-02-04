#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll X[16], Y[16], P[16];
ll ans[16];
ll costx[65536];
ll costy[65536];

int main(){
  int N;
  cin >> N;
  REP(i,N) cin >> X[i] >> Y[i] >> P[i];
  REP(i,N) ans[i] = 10000LL * 15LL * 2000000LL;
  // sen ： bit i が 1 なら、i番目の集落上に線を引いている
  // dir ： bit i が、i番目の集落上に引いている線の方向 0:横方法

  // costx[ sen ] : sen位置に縦方向の線路がある場合の、X方向の最低コスト
  // costy[ sen ] : sen位置に横方向の線路がある場合の、Y方向の最低コスト
  REP(sen, 1 << N) {

    
  REP(dir, 1 << N ) REP(sen, 1 << N) {
    ll K = 0;
    REP(i,N) if ( (sen & (1 << i))!=0 ) K++;
    ll cost = 0;
    REP(i,N) {
      ll mx = abs(X[i]), my = abs(Y[i]);
      REP(j,N) {
        if ( (sen & (1 << j))!=0 ) {
          if ( (dir & (1 << j))!=0 )
            mx = min( mx, abs(X[i]-X[j]) );
          else 
            my = min( my, abs(Y[i]-Y[j]) );
        }
      }
      cost += min(mx,my) * P[i];
    }
    ans[K] = min( ans[K], cost );
  }
  REP(i,N+1) cout << ans[i] << endl;
}
