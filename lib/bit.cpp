#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// BIT(Binary Index Tree)
//  [1,n) 範囲での合計値を、O(logN)で更新、算出できる
template <typename T = int>
struct BIT {
  int N;
  vector<T> node;
  BIT( int size ) : N(size+1), node(N,0) {}

  // 加算
  void add( int i, T x ) {
    for ( int idx=i+1; idx<=N; idx+=(idx & (-idx)) ) node[idx] += x;
  }
  // [0,i) の区間和
  T sum( int i ) {
    T ret = 0;
    for ( int idx=i+1; idx>0; idx-=(idx&(-idx)) ) ret += node[idx];
    return ret;
  }
};

int main() {
  BIT<int> bit(8);
  REP(i,8) bit.add(i, 1);
  REP(i,8)
    cout << i+1 << " : " << bit.sum(i) << endl;
  bit.add(5, 2);
  REP(i,8)
    cout << i+1 << " : " << bit.sum(i) << endl;
}

  