// idx번째 비트 켜져있는지 확인하기

#include <bits/stdc++.h>
using namespace std;

int main () {
  int S = 18; // 10010;
  int idx = 4;

  cout << idx << "가 ";
  if (S & (1 << idx)) {
    cout << "켜져 있습니다. \n";
  } else {
    cout << "꺼져 있습니다. \n";
  }

  return 0;
}