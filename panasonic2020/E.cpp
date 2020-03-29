#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

bool match( char a, char b ) {
  if ( a=='?' || b=='?' || a == b ) return true;
  else return false;
}


int main() {
  string a,b,c;
  cin >> a >> b >> c;

  vector<bool> ab(6000,true), bc(6000,true), ca(6000,true);
  vector<bool> ba(6000,true), cb(6000,true), ac(6000,true);

  // •¶š”‚ğ a < b < c ‚É‚·‚é
  int la = a.length();
  int lb = b.length();
  int lc = c.length();
  if ( la > lb ) swap(a,b);
  if ( la > lc ) swap(a,c);
  if ( lb > lc ) swap(b,c);
//  cout << a << endl;
//  cout << b << endl;
//  cout << c << endl;
  la = a.length();
  lb = b.length();
  lc = c.length();
  
  // a-b
  REP(i, la)
    REP(j, min( la-i, lb))
      if (!match(a[i+j],b[j])) { ab[i] = false; break; }
  // a-c
  REP(i, la)
    REP(j, min( la-i, lc))
      if (!match(a[i+j],c[j])) { ac[i] = false; break; }
  // b-c
  REP(i, lb)
    REP(j, min( lb-i, lc))
      if (!match(b[i+j],c[j])) { bc[i] = false; break; }
  // b-a
  REP(i, lb)
    REP(j, min( lb-i, la))
      if (!match(b[i+j],a[j])) { ba[i] = false; break; }
  // c-a
  REP(i, lc)
    REP(j, min( lc-i, la))
      if (!match(c[i+j],a[j])) { ca[i] = false; break; }
  // c-b
  REP(i, lc)
    REP(j, min( lc-i, lb))
      if (!match(c[i+j],b[j])) { cb[i] = false; break; }

  int ans = la + lb + lc;
  // a-b-c
  REP(j,la+lb) REP(i,j+1) if( ab[i] && bc[j-i] && ac[j])  {
    ans = min( max({la,j+lc,i+lb}), ans );
//    cout << i << " " << j << endl;
//    break;
  }
  // a-c-b
  REP(j,la+lc) REP(i,j+1) if( ac[i] && cb[j-i] && ab[j])  ans = min( max({la,i+lc,j+lb}), ans );
  // b-a-c
  REP(j,lb+la) REP(i,j+1) if( ba[i] && ac[j-i] && bc[j] )  ans = min( max({lb,i+la,j+lc}), ans );
  // b-c-a
  REP(j,lb+lc) REP(i,j+1) if( bc[i] && ca[j-i] && ba[j] )  ans = min( max({lb,i+lc,j+la}), ans );
  // c-a-b
  REP(j,lc+la) REP(i,j+1) if( ca[i] && ab[j-i] && cb[j] )  ans = min( max({lc,i+la,j+lb}), ans );
  // c-b-a
  REP(j,lc+lb) REP(i,j+1) if( cb[i] && ba[j-i] && ca[j] )  ans = min( max({lc,i+lb,j+la}), ans );

  cout << ans << endl;
}


