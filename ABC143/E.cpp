#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

using fuel = pair<ll,ll>;
ll ans[301][301];

int main() {
  int N, M;
  ll L;
  cin >> N >> M >> L;
  vector< vector< pair<int,int> > > to(N);
  REP(i,M)  {
    int ai,bi;
    ll ci;
    cin >> ai >> bi >> ci;
    if ( ci > L ) continue;
    ai--; bi--;
    to[ai].emplace_back(bi, ci);
    to[bi].emplace_back(ai, ci);
  }
  // ダイクストラで全部のノードからの給油回数をあらかじめ求める
  REP(i, N) {
    vector< fuel > v;
    REP(j,N) {
      v.emplace_back( INF, INF );
    }
    v[i].first = 0;
    v[i].second = 0;

    priority_queue< pair<fuel, int>,
                    vector< pair<fuel, int> >,
                    greater< pair<fuel, int> > > q;
    q.push( make_pair(fuel(0,0), i ) );
    
    while ( !q.empty() ) {
      auto nv = q.top();
      q.pop();
      
      int nv_num = nv.second;
      ll nv_c = nv.first.first;
      ll nv_dist = nv.first.second;
      
      for( auto x : to[nv_num] ) {
//        cout << i << " : " << nv_num << " - " << x.second << " -> " << x.first << endl;
        int next_num = x.first;
        ll next_dist = x.second + nv_dist;
        ll next_c = nv_c;
        if ( next_dist > L ) {
          next_dist = x.second;
          next_c++;
        }
        if ( v[next_num] > make_pair(next_c, next_dist) ) {
          v[next_num] = make_pair(next_c, next_dist);
          q.push( make_pair( v[next_num], next_num ) );
//          cout << "  " << next_c << " " << next_dist << endl;
        }
      }
    }
    REP(j,N) {
      ans[i][j] = v[j].first;
    }
  }

  int Q;
  cin >> Q;
  REP(i, Q) {
    int s,e;
    cin >> s >> e;
    s--; e--;
    ll res = ans[s][e];
    if ( res == INF ) res = -1;
    cout << res << endl;
  }

}
