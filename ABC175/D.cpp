#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int gp[5005];
ll gp_sc[5005];
ll gp_size[5005];

int main(){
  ll N,K;
  cin >> N >> K;
  vector< int > P(N+1);
  vector< ll > C(N+1);
  REP(i,N) cin >> P[i], P[i]--;
  REP(i,N) cin >> C[i];

  // グループ番号付与 1から始まる数字
  //  グループごとのサイズとスコア合計も計算
  int gn = 1;
  REP(i,N) {
    if ( gp[i] != 0 ) continue;
    ll tmp_sc= 0;
    ll tmp_size = 0;
    int j = i;
    while ( gp[j] == 0 ) {
      gp[j] = gn;
      tmp_sc += C[j];
//      cout << " " << j << " " << gn << " " << tmp_sc << endl;
      tmp_size++;
      j = P[j];
    }
    gp_sc[gn] = tmp_sc;
    gp_size[gn] = tmp_size;
    gn++;
  }
/*
  REP(i,10) cout << gp[i] << " ";
  cout << endl;
  REP(i,10) cout << gp_size[i] << " ";
  cout << endl;
  REP(i,10) cout << gp_sc[i] << " ";
  cout << endl;
*/
  ll ans = -10000000000LL;

  // マスごとにスコア計算
  REP(i,N) {
    // 必ず1回は動かす
    ll k1 = K - 1;
    ll nowsc = C[ P[i] ];
//    cout << i << " : " << k1 << " " << nowsc << endl;
    // 所属グループの一周のスコアを見て、プラスなら何回も回る。
    if ( gp_sc[ gp[i] ] > 0 ) {
      if ( k1 >= gp_size[ gp[i] ] ) 
        nowsc += (gp_sc[ gp[i] ] * (k1 / gp_size[ gp[i] ]));
      k1 = k1 % gp_size[ gp[i] ];
//    cout << i << "  : " << k1 << " " << nowsc << endl;
    } else {
      // マイナスなら、最大でも一周
      k1 = min(k1, gp_size[ gp[i] ]);
    }
    // 残りステップ数を回って、最大スコアを残す
    ll tmpsc = nowsc;
    int ni = P[i];
    REP(j, k1) {
      tmpsc += C[ P[ni] ];
      nowsc = max( nowsc, tmpsc );
      ni = P[ni];
//      cout << i << "  :  " << j << " : " << nowsc << endl;
    }
    ans = max( nowsc, ans );
  }
  cout << ans << endl;
}
