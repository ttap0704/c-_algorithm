#include <bits/stdc++.h>
using namespace std;

bool a[10][10];

void go (int i) {
  if (i > 10) return;

  for (int j = 0; j < 10; j++) {
    if (a[i][j] == 1) {
      cout << "i/j : " << i << "/" << j << "\n";
    }
  } 

  go(i + 1);
}

int main () {
  a[1][2] = 1;
  a[2][1] = 1;
  a[1][3] = 1;
  a[3][1] = 1;
  a[3][4] = 1;
  a[4][3] = 1;

  go(0);
  
  return 0;
}