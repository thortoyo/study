#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

double dp[601], dp2[601];

int main() {
  int N, M;
  cin >> N >> M;
  vector< vector<int> > to(N), ot(N);	// �ڑ���A�ڑ���
  vector< int > o(N,0);	// �o����
  vector< double > p(N,0);	// �����m��

  REP(i,M) {
    int src, dst;
    cin >> src >> dst;
    src--; dst--;
    to[src].push_back(dst);
    ot[dst].push_back(src);
    o[src]++;
  }

  // ������Ԃł̊��Ғl����
  for (int i=N-2; i>=0; --i ) {
    for ( auto r: to[i] ) {
      dp[i] += dp[r];
    }
    dp[i] /= o[i];
    dp[i] += 1;
  }

  // ������Ԃł̓����m������
  p[0] = 1;
  for( int i=0; i<N; i++ ) {
    for ( auto r: to[i] ) {
      p[r] += p[i] / o[i];
    }
  }

//  REP(i,N)
//    cout << i << " : " << p[i] << " " << dp[i] << endl;

  double E = dp[0];
  REP(i,N) dp2[i] = dp[i];

  // �O���珇�Ɉ�Ԋ��Ғl�ɉe�����傫���ӂ��폜���Ċ��Ғl�Čv�Z����
  for (int i=0; i<N-1; ++i ) {
    if (o[i] == 1) continue;	// �o������1�Ȃ�폜�ł��Ȃ�
    vector< double > v;
    for ( auto r: to[i] ) v.push_back(dp[r]);
    sort(v.begin(), v.end());
    v.pop_back();		// ��ԑ傫�����Ғl�����O
    // �������ӂ̎n�_�̊��Ғl�Čv�Z
    dp2[i] = 0;
    for( auto x: v ) dp2[i] += x;
    dp2[i] /= (o[i]-1);
    dp2[i] += 1;
    // ���݈ʒu����O�̊��Ғl�Čv�Z
    for (int j=i-1; j>=0; --j) {
      dp2[j] = 0;
      for ( auto r: to[j] ) {
        dp2[j] += dp2[r];
      }
      dp2[j] /= o[j];
      dp2[j] += 1;
    }
    E = min( E, dp2[0] );
    
    REP(k,N) dp2[k] = dp[k];
  }
  cout << fixed << setprecision(10) << E << endl;
}
