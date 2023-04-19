// 모든 비트 다 켜기
// n인 집합에 대해 모든 비트 켜기
#include <bits/stdc++.h>
using namespace std;

int main () {
  int n = 4;
  cout << (1 << n) - 1 << "\n"; // 15
  return 0;
}