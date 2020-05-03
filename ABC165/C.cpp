#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int N,M,Q;
  cin >> N >> M >> Q;
  vector< int > a(50), b(50), c(50), d(50), m(10);
  REP(i,Q) {
    cin >> a[i]  >> b[i]  >> c[i]  >> d[i] ;
    a[i]--; b[i]--;
  }
  
  REP(i,10) {
    if ( i < M ) m[i] = M+1;
    else m[i] = 0;
  }
  vector< int > A(10,0);
  int ans = 0;
  for (A[0]=1; A[0]<M+1; A[0]++ )
    for( A[1]=A[0]; A[1]<M+1; A[1]++ )
      for( A[2]=A[1]; A[2]<M+1; A[2]++ )
        for( A[3]=A[2]; A[3]<M+1; A[3]++ )
          for( A[4]=A[3]; A[4]<M+1; A[4]++ )
            for( A[5]=A[4]; A[5]<M+1; A[5]++ )
              for( A[6]=A[5]; A[6]<M+1; A[6]++ )
                for( A[7]=A[6]; A[7]<M+1; A[7]++ )
                  for( A[8]=A[7]; A[8]<M+1; A[8]++ )
                    for( A[9]=A[8]; A[9]<M+1; A[9]++ ) {
                      int sum = 0;
                      REP(i,Q) {
                        if ( A[b[i]]-A[a[i]] == c[i] ) sum += d[i];
                      }
                      ans = max( ans, sum );
                    }

  cout << ans << endl;
}
