// idx번째의 비트 켜기

#include <bits/stdc++.h>
using namespace std;

int main () {
  int S = 18; // 10010;
  int idx = 3;
  S |= (1 << idx);

  cout << S << "\n";
  return 0;
}