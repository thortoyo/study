#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

vector< vector<int> > to(2505);
vector< vector<int> > ot(2505);
vector<bool> toOK(2505,false);
vector<bool> otOK(2505,false);
vector<bool> ok(2505,false);

// �����ʒu���炽�ǂ蒅����ꏊ��BFS�Ō���
void bfs( int v ) {
  if (toOK[v]) return;
  toOK[v] = true;
  for( auto a: to[v] ) {
    bfs( a );
  }
}
// �S�[���ʒu�ɂ��ǂ蒅����ꏊ��BFS�Ō���
// �S�[������T������̂ŋt�����ɂ������̂��g�p
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
    --a; --b;	// 0-index �ɂ���
    c -= P;
    c = -c;	// �}�C�i�X�ɂ��邱�ƂōŒZ�p�X�̌������g����
    G.emplace_back(a,b,c);
    to[a].push_back(b);
    ot[b].push_back(a);
  }
  // ���B�\����T��
  bfs(0);
  bfs2(N-1);

  // �X�^�[�g�n�_���炽�ǂ蒅���Ȃ� or �S�[���ɂ��ǂ蒅���Ȃ��̂��O��
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

  // �x���}��-�t�H�[�h�@
  //  �ӂ̏d�݂��}�C�i�X�ł��g����
  while (upd ) {
    // �S�Ă̕ӂ�T�����A�ω����Ȃ��Ȃ�܂ő�����
    upd = false;
    for (int i=0;i<M;++i) {
      int a,b,c;
      tie(a,b,c) = G[i];
      if ( !ok[a] ) continue;
      if ( !ok[b] ) continue;
      if ( dist[b] > dist[a] + c ) {
        // �P���ɁA���̕ӂ�ʂ����ق����������Z���Ȃ�Ȃ�A������̗p����
        dist[b] = dist[a] + c ;
        upd = true;
//        cout << step << " | " << a << " -> " << b << " : " << -dist[b] << endl;
      }
    }
    step++;
    if ( step > N ) {
      // �S���_���𒴂��Ă��ω����Ă�΁A����͕��̃��[�v�����邱�Ƃ�����
      cout << "-1" << endl;
      return 0;
    }
//    cout << step << " | N: " << -dist[N-1] << endl;
  }
  
  
  cout << max(-dist[N-1],0) << endl;

}
