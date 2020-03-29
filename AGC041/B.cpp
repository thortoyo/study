#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll M,N,V,P;
vector< ll > A;

bool judge( ll mid ) {
//  cout << " A[mid] " << A[mid] << endl;
  // A[mid]+M < A[P-1] �Ȃ牽������Ă�NG
  if ( A[mid] + M < A[P-1] ) return false;

  ll zan = (V-1) * M;
//  cout << " " << zan << endl;
  // A[mid]+M �����傫���X�R�A�� P-1 �ȉ��Ȃ�OK
  //  A[mid+1]�`A[N-1] �� +M ���Ă��e���Ȃ��B
  zan -= (N-(mid+1)) * M;
//  cout << " " << zan << endl;
  //  �傫������ P-1 �ڂ܂ł� +M ���Ă��e���Ȃ��B
  zan -= (P-1) * M;
//  cout << " " << zan << endl;
  if ( zan <= 0 ) return true;
  // �c���� A[P-1] �` A[mid-1] �܂ł̋�ԂŁAA[mid] �𒴂��Ȃ��悤�ɑ���
  for (int i=P-1; i<mid; i++) {
    zan -= (A[mid]+M-A[i]);
//    cout << " " << zan << endl;
    if ( zan <= 0 ) return true;
  }
  return false;		// ����ł��]������NG
}

int main() {
  cin >> N >> M >> V >> P;
  REP(i,N) {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end(), greater<ll>() );
  
  ll l = P-1;	// �傫������P�ڂ܂ł́A��������OK
  ll r = N;
  ll mid;
  while( l+1 < r ) {
    mid = (l+r)/2;
    if ( judge(mid) ) {
//      cout << mid << " OK" << endl;
      l = mid;
    } else {
//      cout << mid << " NG" << endl;
      r = mid;
    }
  }
  cout << (l+1) << endl;
}
