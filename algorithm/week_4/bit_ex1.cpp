#include <bits/stdc++.h>
using namespace std;

int main () {
  // idx번째 비트 끄기
  int S1 = 18; // 10010;
  int idx1 = 1;

  S1 &= ~(1 << idx1); // 10000 -> 16
  cout << "비트 끄기 : " << S1 << "\n";

  // idx번째 : 0은 1로, 1은 0으로
  int S2 = 18; // 10010;
  int idx2 = 0;

  S2 ^= (1 << idx2); // 10011 -> 19
  cout << "비트 XOR : " << S2 << "\n";

  // 최하위 켜져있는 index 찾아내기
  int S3 = 18; // 10010;
  int idx3 = (S3 & -S3);
  cout << "최하위 켜져있는 Index 찾기 : " << idx3 << "\n";

  // 모든비트 다 켜기
  int N = 4;
  int S4 = (1 << N) - 1; // 15
  cout << "모든비트 다 켜기 : " << S4 << '\n';

  // idx번째의 비트 켜기
  int S5 = 18; // 10010;
  int idx5 = 0;
  S5 |= (1 << idx5); // 19
  cout << "id번째 비트 켜기 : " << S5 << '\n';

  // idx번째 비트가 켜져있는지 확인하기
  int S6 = 18; // 10010;
  int idx6 = 3;
  cout << idx6 << "번재 비트가 ";
  if (S6 & (1 << idx6)) {
    cout << "켜져있습니다.\n";
  } else {
    cout << "꺼져있습니다.\n";
  }
  return 0;
}