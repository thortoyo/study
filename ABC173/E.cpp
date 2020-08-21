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
    // N == K �Ȃ̂ŁA�S���̗p���邵���Ȃ�
    REP(i,K) {
      ans = ans * A[i].first;
      ans = ans * ((A[i].second == 1) ? -1 : 1);
    }
  } else if (allm == true && (K%2==1) ) {
    // �S�����ŁA��I�ԂȂ�K�����ɂȂ�̂ŁA��Βl�����������ɂ�����
    sort(A.begin(), A.end());
    REP(i,K) {
      ans = ans * A[i].first;
    }
    ans *= -1;
  } else {
    // ��Βl���傫�����ɑI��
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    bool s = false;
    ll last_m = -1, last_p = -1;
    REP(i,N) {
//      cout << i << " : " << ans << " " << s << endl;
      if ( i == K ) {		// �S���I��
        if ( !s ) {
          // ���܂ł̌��ʂ����̏ꍇ�͂��ꂪ����
          if ( last_m != -1 ) ans *= last_m;
          if ( last_p != -1 ) ans *= last_p;
          break;
        } else {
          // ���܂ł̌��ʂ����̏ꍇ�A�ȉ��̂ǂ��炩�傫����
          // �E���̐���1�����āA���ɑ傫�ȕ��̐���������
          // �E���̐���1�����āA���ɑ傫�Ȑ��̐���������
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
            // �E���̐���1�����āA���ɑ傫�ȕ��̐���������
            //  -> �Ō�̕��̐��ƁA���̕��̐����|����
            ans0 = next_m;
            if ( last_m != -1 ) ans0 *= last_m;
          }
          if ( last_m != -1 && next_p != -1) {
            // �E���̐���1�����āA���ɑ傫�Ȑ��̐���������
            //  -> �Ō�̐��̐��ƁA���̐��̐����|����
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
        // ���̐��̏ꍇ
        if ( last_p != -1 ) ans *= last_p;
        last_p = A[i].first;
      } else {
        // ���̐��̏ꍇ
        if ( last_m != -1 ) ans *= last_m;
        last_m = A[i].first;
        s = !s;
      }
    }
  }
  cout << ans.x << endl;
}
