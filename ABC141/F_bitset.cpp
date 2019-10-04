#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  ll ans = 0;
  cin >> N;
  vector<ll> A(N);
  vector< bitset<100010> > B(60, bitset<100010>(0));
  ll all_a = 0;
  REP(i, N) {
    ll ain;
    cin >> A[i];
    all_a ^= A[i];
  }
  // 全部XORを取った値で、1 になったbitはどのような分け方をしても、片方は偶数、もう片方は奇数になるので、
  // そのbitは考慮しなくてOK。
  // 最終的に和を求める際に、そのbitは 0+1 か 1+0 にしかならないので、和は 1 になる。
  // つまり、この all_a そのものを足せばいい。
  // 0 になった bit は 偶数と偶数、奇数と奇数 のどちらかになる。
  // 当然、奇数＋奇数になったほうが和は大きいので、それを目指す。

  // 考慮しないbitの情報を消す
  REP(i,N) A[i] &= ~all_a;

  // 考慮しない桁の和は 1 になるので、先に足しておく
  ans = all_a;
  
  // 掃き出し法が使えるように
  //  B[0] = [ A[0].bit59, A[1].bit59,,, A[N-1].bit59, 1 ] 
  //  B[1] = [ A[0].bit58, A[1].bit58,,, A[N-1].bit58, 1 ] 
  // という2次元配列に格納
  REP(i,60) {
    REP(j,N) {
      B[59-i][j] = (A[j] >> i) & 1;
    }
    B[59-i][N] = 1;
  }
  
  // 掃き出し法
  //  ただし、できるだけ上位Bitが1になる解がいいので、上位側から優先して判定する
  //  上記で考慮しないbitにした桁は、対応する行の値が全て 0 になっている。
  //  そのため、pivotに選ばれることはないし、0 なので xor 演算の対象になることもない。
  //  なので、最後まで同じ形 (0 0 0...0 | 1) をしているはず
  vector<bool> use(60,false);
  REP(col,N) {
    int pivot = -1;
    // Pivot探す
    REP(row,60) {
      if (use[row]) continue;
      if (B[row][col] == 1) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    
    // 見つかったpivot以外の行の、現在の列の値を 0 にしていく
    REP(row,60) {
      if ((row != pivot) && (B[row][col] == 1)) {
        B[row] ^= B[pivot];
      }
    }
    use[pivot] = true;
  }

  
  // (0 0 0 0 | 1) となっている桁は無視
  REP(row,60) {
    bool ok = false;
    if ( (B[row][N] == 0) ) ok = true;
    REP(col,N)
      if ( B[row][col] == 1 ) ok = true;
    // 2グループのどちらも 1 になるので、合計値はその桁が 2 になったものになる
    if (ok) 
      ans += (2LL << (59-row));
  }

  cout << ans << endl;
}
