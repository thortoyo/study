#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll N,K;
vector< ll > A(200000);

// Še Ai ‚ð a ‚ÅŠ„‚Á‚Ä‚¢‚Á‚ÄAK ŒÂˆÈ‰º‚É•ªŠ„‚Å‚«‚½‚ç true
// K ŒÂ‚æ‚è•ªŠ„‚ª‘½‚­‚È‚é‚È‚ç false
bool check(ll k){
  ll divn = 0;
  REP(i,N) {
    divn += (A[i]-1) / k;
    if ( divn > K ) return false;
  }
  return true;
}

int main(){
  cin >> N >> K;
  REP(i,N) {
    cin >> A[i];
    A[i] *= 100;
  }
  ll l = 1;
  ll r = 100000000000;
  while ( l+1 < r ) {
    ll mid = (l + r) / 2;
//    cout << l << " " << mid << " " << r << " : ";
    if ( check( mid ) )
      r = mid;
    else
      l = mid;
//    cout << " -> " << l << " " << r << endl;
  }
  cout << ((r+99)/100) << endl;
}
