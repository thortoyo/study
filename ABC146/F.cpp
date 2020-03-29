// �S�[������t�Z����B
// �S�[�����炷��ƁA��ԉ��������ɍs���̂��萔�����Ȃ����邽�߂ɂ͍őP�B
// �Ȃ̂ŁA�S�[������M�̋������珇�ɓ����ł���Ƃ����T���B
// M �ȓ��ɃX�^�[�g�n�_�������ꍇ�A���O�ɖ߂��ăX�^�[�g�n�_����
// 2��Ői�ޏꍇ��1��ڂ���ԏ����������ɂȂ�ꍇ��T���H

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;


int main() {
  int N,M;
  string S;
  cin >> N >> M >> S;
  int now = N;
  vector<int> r;
  
  if ( N <= M ) {
    cout << min(N,M) << endl;
    return 0;
  }

  while ( now-M > 0 ) {
    int jump = 0;
    for(jump=M; jump>0; --jump) {
      if ( S[now-jump] == '1' ) continue;
      r.emplace_back( jump );
      break;
    }
    if ( jump==0 ) {
      cout << "-1" << endl;
      return 0;
    }
    now -= jump;
  }
  if ( now-M == 0 ) {
    r.emplace_back( M );
  } else {
    int &pre = r.back();
    r.pop_back();
    now += pre;
    for(int jump=1; jump<=M; ++jump) {
      if ( S[jump] == '1' ) continue;
      if ( jump+M < now ) continue;
      r.emplace_back( now-jump );
      r.emplace_back( jump );
      break;
    }
  }
  reverse( r.begin(), r.end() );
  for (auto x: r ) cout << x << " ";
  cout << endl;
}
