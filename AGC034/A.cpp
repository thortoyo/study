#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,N;
  string S;
  cin >> N >> A >> B >> C >> D;
  cin >> S;
  int ng = 0;
  int wall = 0;
  int r = 0;
  int ov = 0;
  if (D>C) {
    for (int i=A-1;i<C;++i ) {
	  if (S[i] == '#') {
    	  if (wall == 1) {
            ng = 1;
            break;
          }
          wall = 1;
      } else {
        wall = 0;
      }
    }
    wall = 0;
    if (ng==0) {
      for (int i=B-1;i<D;++i ) {
	    if (S[i] == '#') {
    	  if (wall == 1) {
            ng = 1;
            break;
          }
          wall = 1;
        } else {
          wall = 0;
        }
      }
    }
  } else {
    ov = 1;
    int dd = D+1;
    if (D==N) {
      dd = D;
    }
    for (int i=B-2;i<dd;++i ) {
	  if (S[i] == '#') {
        if (ov!=2) ov = 0;
        r = 0;
        if (wall == 1) {
          ng = 1;
          break;
        }
        wall = 1;
      } else {
        ++r;
        if (r>2) ov = 2;
        wall = 0;
      }
    }
    if (ov==0) {
      ng = 1;
    }
    if (ng==0) {
      for (int i=A-1;i<C;++i ) {
	    if (S[i] == '#') {
    	  if (wall == 1) {
            ng = 1;
            break;
          }
          wall = 1;
        } else {
          wall = 0;
        }
      }
    }
  }
  if (ng==0) {
	  cout << "Yes" << endl;
  } else {
	  cout << "No" << endl;
  }
    
  return 0;
}
  
