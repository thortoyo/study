#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<double> x(N), y(N);
  vector<int> v(N);
  REP(i,N) {
    cin >> x[i] >> y[i];
    v[i] = i;
  }
  double total = 0;
  REP(i,N-1) {
    for( int j = i+1; j<N; ++j ) {
      double d = sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      total += d * 2 / N;
    }
  }
  cout << fixed << setprecision(10) << total << endl;
}
