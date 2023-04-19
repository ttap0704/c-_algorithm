// idx번째 비트 XOR 연산자
// 0은 1로, 1은 0으로

#include <bits/stdc++.h>
using namespace std;

int main () {
  int S = 18; // 10010;
  int idx = 0;
  
  S ^= (1 << idx);
  cout << S << "\n";

  return 0;
}