#include <bits/stdc++.h>
using namespace std;
int H,W;
int g_w[2002][2002];
int g_h[2002][2002];
int main() {
  cin >> H >> W;
  int cnt_w = 0;
  int cnt_h = 0;
  // ‰¡˜A‘±
  for (int i=0;i<H;i++ ) {
    string s;
    cin >> s;
    for ( int j=0;j<W;++j) {
      if (s[j] == '.') {
        ++cnt_w;
      } else {
        if (cnt_w>0) {
          for (int k=j-cnt_w;k<j;++k) {
            g_w[i][k] = cnt_w;
          }
        }
        cnt_w = 0;
      }
    }
    if( cnt_w>0) {
      for (int k=W-cnt_w;k<W;++k) {
        g_w[i][k] = cnt_w;
      }
      cnt_w = 0;
    }
  }
  // c˜A‘±
  for (int j=0;j<W;++j ) {
    for ( int i=0;i<H;++i) {
      if (g_w[i][j] != 0) {
        ++cnt_h;
      } else {
        if (cnt_h>0) {
          for (int k=i-cnt_h;k<i;++k) {
            g_h[k][j] = cnt_h;
          }
        }
        cnt_h = 0;
      }
    }
    if( cnt_h>0) {
      for (int k=H-cnt_h;k<H;++k) {
        g_h[k][j] = cnt_h;
      }
      cnt_h = 0;
    }
  }
/*  
  for (int i=0;i<H;++i) {
    for (int j=0;j<W;++j) {
      cout << g_w[i][j];
    }
    cout << endl;
  }
  cout << endl;
  for (int i=0;i<H;++i) {
    for (int j=0;j<W;++j) {
      cout << g_h[i][j];
    }
    cout << endl;
  }
  */
  int mv = 0;
  for (int i=0;i<H;++i) {
    for (int j=0;j<W;++j) {
//      g_w[i][j] += g_h[i][j] - 1;
      mv = max(mv, g_w[i][j]+ g_h[i][j] - 1);
    }
  }
  cout << mv << endl;
}
  
