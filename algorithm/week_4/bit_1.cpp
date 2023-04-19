// idx번째의 비트 끄기 (0으로 만들기)

#include <bits/stdc++.h>
using namespace std;
int main () {
  int S = 18; // 10010;
  int idx = 1; // 1번째

  S &= ~(1 << idx); // 10000
  cout << S << "\n";
  return 0;
}