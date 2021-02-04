#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}



int main(){
  ll N,K;
  cin >> N >> K;
  vector< pair<ll,int> > A(N);
  bool allm = true;
  REP(i,N) {
    ll a;
    cin >> a;
    A[i].first = abs(a);
    A[i].second = (a<0) ? 1 : 0;
    if (a>0) allm = false;
  }
  mint ans = 1;
  
  if ( N==K ) {
    // N == K なので、全部採用するしかない
    REP(i,K) {
      ans = ans * A[i].first;
      ans = ans * ((A[i].second == 1) ? -1 : 1);
    }
  } else if (allm == true && (K%2==1) ) {
    // 全部負で、奇数個選ぶなら必ず負になるので、絶対値が小さい順にかける
    sort(A.begin(), A.end());
    REP(i,K) {
      ans = ans * A[i].first;
    }
    ans *= -1;
  } else {
    // 絶対値が大きい順に選ぶ
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    bool s = false;
    ll last_m = -1, last_p = -1;
    REP(i,N) {
//      cout << i << " : " << ans << " " << s << endl;
      if ( i == K ) {		// 全部選んだ
        if ( !s ) {
          // 今までの結果が正の場合はこれが答え
          if ( last_m != -1 ) ans *= last_m;
          if ( last_p != -1 ) ans *= last_p;
          break;
        } else {
          // 今までの結果が負の場合、以下のどちらか大きい方
          // ・正の数を1個除いて、次に大きな負の数を加える
          // ・負の数を1個除いて、次に大きな正の数を加える
          ll ans0 = -1, ans1 = -1;
          ll next_m = -1, next_p = -1;
          for( int j=i; j<N; j++ ) {
            if ( A[j].second == 0 ) {
              if ( next_p == -1 ) next_p = A[j].first;
            } else {
              if ( next_m == -1 ) next_m = A[j].first;
            }
          }
          if ( last_p != -1 && next_m != -1) {
            // ・正の数を1個除いて、次に大きな負の数を加える
            //  -> 最後の負の数と、次の負の数を掛ける
            ans0 = next_m;
            if ( last_m != -1 ) ans0 *= last_m;
          }
          if ( last_m != -1 && next_p != -1) {
            // ・負の数を1個除いて、次に大きな正の数を加える
            //  -> 最後の正の数と、次の正の数を掛ける
            ans1 = next_p;
            if ( last_p != -1 ) ans1 *= last_p;
          }
//          cout << " last_m " << last_m << " , last_p " << last_p << endl;
//          cout << " next_m " << next_m << " , next_p " << next_p << endl;
//          cout << " ans0 " << ans0 << " , ans1 " << ans1 << endl;
          ans *= max( ans0, ans1 );
          break;
        }
      }
      
      if ( A[i].second == 0 ) {
        // 正の数の場合
        if ( last_p != -1 ) ans *= last_p;
        last_p = A[i].first;
      } else {
        // 負の数の場合
        if ( last_m != -1 ) ans *= last_m;
        last_m = A[i].first;
        s = !s;
      }
    }
  }
  cout << ans.x << endl;
}
