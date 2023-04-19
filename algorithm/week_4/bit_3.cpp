// 최하위 커져있는 비트 index 알아내기
#include <bits/stdc++.h>
using namespace std;

int main () {
  int S = 18; // 10010;
  int idx = (S & -S);

  cout << idx << "\n"; // 2
  return 0;
}