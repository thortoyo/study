#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M;
  cin >> N >> M;
  vector< vector<int> > AB(M+1);

  for( int i=0; i<N; ++i) {
    int a,b;
    cin >> a >> b;
    if ( a > M ) continue;
    AB[M-a].push_back(b);
  }

  priority_queue<int> jobs;

  int64_t ans = 0;
  // M���ڂ���T��
  for( int t=M-1; t>=0; --t) {
//    cout << "--- " << t << " ---" << endl;
    // ���݂̓��Ŏ󂯂�����(t+A<=M)�̒��ŁAB�ő�̂��̂�I��
    for ( auto b: AB[t] ) {
      jobs.push(b);
    }

    if ( !jobs.empty() ) {
      ans += jobs.top();
      jobs.pop();
    }
  }

  cout << ans << endl;

}
