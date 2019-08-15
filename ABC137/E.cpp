#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

vector< vector<int> > to(2505);
vector< vector<int> > ot(2505);
vector<bool> toOK(2505,false);
vector<bool> otOK(2505,false);
vector<bool> ok(2505,false);

// 初期位置からたどり着ける場所をBFSで検索
void bfs( int v ) {
  if (toOK[v]) return;
  toOK[v] = true;
  for( auto a: to[v] ) {
    bfs( a );
  }
}
// ゴール位置にたどり着ける場所をBFSで検索
// ゴールから探索するので逆方向にしたものを使用
void bfs2( int v ) {
  if (otOK[v]) return;
  otOK[v] = true;
  for( auto a: ot[v] ) {
    bfs2( a );
  }
}

int main() {
  int N,M,P;
  cin >> N >> M >> P;
  vector< tuple<int,int,int> > G;

  for( int i=0; i<M; ++i) {
    int a,b,c;
    cin >> a >> b >> c;
    --a; --b;	// 0-index にする
    c -= P;
    c = -c;	// マイナスにすることで最短パスの検索が使える
    G.emplace_back(a,b,c);
    to[a].push_back(b);
    ot[b].push_back(a);
  }
  // 到達可能かを探索
  bfs(0);
  bfs2(N-1);

  // スタート地点からたどり着かない or ゴールにたどり着かないのを外す
  for (int i=0;i<N;++i) {
    if ( toOK[i] && otOK[i] ) {
      ok[i] = true;
//      cout << i << " : OK" << endl;
    }
  }

  vector<int> dist(N,INF);
  dist[0] = 0;
  
  bool upd = true;
  int step = 0;

  // ベルマン-フォード法
  //  辺の重みがマイナスでも使える
  while (upd ) {
    // 全ての辺を探索し、変化がなくなるまで続ける
    upd = false;
    for (int i=0;i<M;++i) {
      int a,b,c;
      tie(a,b,c) = G[i];
      if ( !ok[a] ) continue;
      if ( !ok[b] ) continue;
      if ( dist[b] > dist[a] + c ) {
        // 単純に、この辺を通ったほうが距離が短くなるなら、それを採用する
        dist[b] = dist[a] + c ;
        upd = true;
//        cout << step << " | " << a << " -> " << b << " : " << -dist[b] << endl;
      }
    }
    step++;
    if ( step > N ) {
      // 全頂点数を超えても変化してれば、それは負のループがあることを示す
      cout << "-1" << endl;
      return 0;
    }
//    cout << step << " | N: " << -dist[N-1] << endl;
  }
  
  
  cout << max(-dist[N-1],0) << endl;

}
