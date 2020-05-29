#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// tu[i] ‚ÍŠ÷i‚ÌÅŒã”ö‚Ì” ”Ô†‚ðŽ¦‚·
// par[i] ‚ª -n ‚È‚çAe‚Í–³‚µ‚ÅŠ÷n‚É‚ ‚é
int tu[200005];
int par[200005];
const int INF = 2000000000;

int get_tu(int x) {
  if (par[x] < 0) return (par[x]);
  return par[x] = get_tu(par[x]);
}

int main(){
  int N,Q;
  cin >> N >> Q;

  REP(i,N+1) {
    tu[i] = i;
    par[i] = -i;
  }
  
  REP(i,Q) {
//    REP(i,N+1) cout << tu[i] << " "; cout << endl;
//    REP(i,N+1) cout << par[i] << " "; cout << endl;
//    cout << endl;
    int f,t,x;
    cin >> f >> t >> x;
    int tmp = tu[t];
    tu[t] = tu[f];
    if ( par[x] < 0 ) {
      tu[f] = 0;
    } else {
      tu[f] = par[x];
    }
    if (tmp != 0)
      par[x] = tmp;
    else
      par[x] = -t;
  }
//  REP(i,N+1) cout << tu[i] << " "; cout << endl;
//  REP(i,N+1) cout << par[i] << " "; cout << endl;
  for(int i=1; i<=N; i++) {
    cout << (-get_tu(i)) << endl;
  }
}

