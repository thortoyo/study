#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op[200005][2][3];

void solve() {
  int N, M, Q;
  cin >> N;
  vector<ll> X(N),Y(N);
  REP(i,N) cin >> X[i] >> Y[i];
  cin >> M;
  op[0][0][0] = 0;	// 1がマイナス
  op[0][0][1] = 0;	// 加算
  op[0][0][2] = 0;	// xy入れ替え
  op[0][1][0] = 0;	// 1がマイナス
  op[0][1][1] = 0;	// 加算
  op[0][1][2] = 0;	// xy入れ替え
  REP(i,M) {
    ll a,b;
    cin >> a;
    if (a==1) {
      op[i+1][0][0] = op[i][1][0];
      op[i+1][0][1] = op[i][1][1];
      op[i+1][0][2] = op[i][1][2] ? 0 : 1;
      op[i+1][1][0] = op[i][0][0] ? 0 : 1;
      op[i+1][1][1] = op[i][0][1] * -1;
      op[i+1][1][2] = op[i][0][2] ? 0 : 1;
    } else if (a==2) {
      op[i+1][0][0] = op[i][1][0] ? 0 : 1;
      op[i+1][0][1] = op[i][1][1] * -1;
      op[i+1][0][2] = op[i][1][2] ? 0 : 1;
      op[i+1][1][0] = op[i][0][0];
      op[i+1][1][1] = op[i][0][1];
      op[i+1][1][2] = op[i][0][2] ? 0 : 1;
    } else if (a==3) {
      cin >> b;
      op[i+1][0][0] = op[i][0][0] ? 0 : 1;
      op[i+1][0][1] = 2 * b - op[i][0][1];
      op[i+1][0][2] = op[i][0][2];
      op[i+1][1][0] = op[i][1][0];
      op[i+1][1][1] = op[i][1][1];
      op[i+1][1][2] = op[i][1][2];
    } else {
      cin >> b;
      op[i+1][0][0] = op[i][0][0];
      op[i+1][0][1] = op[i][0][1];
      op[i+1][0][2] = op[i][0][2];
      op[i+1][1][0] = op[i][1][0] ? 0 : 1;
      op[i+1][1][1] = 2 * b - op[i][1][1];
      op[i+1][1][2] = op[i][1][2];
    }
  }
  cin >> Q;
  REP(i,Q) {
    int a,b;
    cin >> a >> b;
    b--;
    ll x,y;
    x = (op[a][0][2] ? Y[b] : X[b]) * (op[a][0][0] ? -1 : 1) + op[a][0][1];
    y = (op[a][1][2] ? X[b] : Y[b]) * (op[a][1][0] ? -1 : 1) + op[a][1][1];
    cout << x << " " << y << endl;
  }
  return;
}

int main(){
  solve();
}
