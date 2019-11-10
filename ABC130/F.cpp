#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

typedef long long ll ;
const ll INF = 1LL << 60;

int main() {

  int N;
  cin >> N;
  vector< double > X(N),Y(N);
  vector< char > D(N);
  vector< double > ti;
  REP(i,N) cin >> X[i] >> Y[i] >> D[i];

  double minc;
  double mdec;
  double mstay;
  ti.push_back(0);	// ŠÔ0‚àŒó•â
  
  // ‰E•ûŒü:XmaxŒó•â
  minc = mdec = mstay = -INF;
  REP(i,N) {
    if (D[i]=='R') minc = max(minc, X[i]);
    else if (D[i]=='L') mdec = max(mdec, X[i]);
    else mstay = max(mstay, X[i]);
  }
  // R‚ªL‚ğ’Ç‚¢‰z‚·
  if (minc != -INF && mdec != -INF) ti.push_back( (mdec - minc)/2 );
  // R‚ªU/D‚ğ’Ç‚¢‰z‚·
  if (minc != -INF && mstay != -INF) ti.push_back( mstay - minc );
  // L‚ªU/D‚ğ’Ç‚¢‰z‚·
  if (mdec != -INF && mstay != -INF) ti.push_back( mdec - mstay );

  // ¶•ûŒü:XminŒó•â
  minc = mdec = mstay = INF;
  REP(i,N) {
    if (D[i]=='R') minc = min(minc, X[i]);
    else if (D[i]=='L') mdec = min(mdec, X[i]);
    else mstay = min(mstay, X[i]);
  }
  // L‚ªR‚ğ’Ç‚¢‰z‚·
  if (minc != INF && mdec != INF) ti.push_back( (mdec - minc)/2 );
  // R‚ªU/D‚ğ’Ç‚¢‰z‚·
  if (minc != INF && mstay != INF) ti.push_back( mstay - minc );
  // L‚ªU/D‚ğ’Ç‚¢‰z‚·
  if (mdec != INF && mstay != INF) ti.push_back( mdec - mstay );

  // ã•ûŒü:YmaxŒó•â
  minc = mdec = mstay = -INF;
  REP(i,N) {
    if (D[i]=='U') minc = max(minc, Y[i]);
    else if (D[i]=='D') mdec = max(mdec, Y[i]);
    else mstay = max(mstay, Y[i]);
  }
  // U‚ªD‚ğ’Ç‚¢‰z‚·
  if (minc != -INF && mdec != -INF) ti.push_back( (mdec - minc)/2 );
  // U‚ªL/R‚ğ’Ç‚¢‰z‚·
  if (minc != -INF && mstay != -INF) ti.push_back( mstay - minc );
  // D‚ªL/R‚ğ’Ç‚¢‰z‚·
  if (mdec != -INF && mstay != -INF) ti.push_back( mdec - mstay );

  // ‰º•ûŒü:YminŒó•â
  minc = mdec = mstay = INF;
  REP(i,N) {
    if (D[i]=='U') minc = min(minc, Y[i]);
    else if (D[i]=='D') mdec = min(mdec, Y[i]);
    else mstay = min(mstay, Y[i]);
  }
  // U‚ªD‚ğ’Ç‚¢‰z‚·
  if (minc != INF && mdec != INF) ti.push_back( (mdec - minc)/2 );
  // U‚ªL/R‚ğ’Ç‚¢‰z‚·
  if (minc != INF && mstay != INF) ti.push_back( mstay - minc );
  // D‚ªL/R‚ğ’Ç‚¢‰z‚·
  if (mdec != INF && mstay != INF) ti.push_back( mdec - mstay );

  double ans = INF;
  for ( auto t: ti ) {
//    cout << t << endl;
    if ( t < 0 ) t = abs(t);
    double xmax, ymax, xmin, ymin;
    xmax = ymax = -INF;
    xmin = ymin = INF;
    REP(i,N) {
      double xi = X[i];
      double yi = Y[i];
      if (D[i] == 'R') xi += t;
      else if (D[i] == 'L') xi -= t;
      else if (D[i] == 'U') yi += t;
      else yi -= t;
      xmax = max( xmax, xi );
      ymax = max( ymax, yi );
      xmin = min( xmin, xi );
      ymin = min( ymin, yi );
    }
//    cout << xmax<< " " << xmin << " " << ymax << " " <<ymin << endl;
    ans = min( ans, (xmax-xmin)*(ymax-ymin) );
  }
  cout << fixed << setprecision(10) << ans << endl;
//  cout << ans << endl;

}

