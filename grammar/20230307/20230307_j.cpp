// 정적 메모리 할당
// Data segment
// 전역변수, static, const로 선언되어있는 변수 중
// 0이 아닌 값으로 초기화된 변수
// Data segment 메모리 영역에 할당 됨

#include <bits/stdc++.h>
using namespace std;

int a = 1;
const int b = 2;

int main () {
  static int c = 3;
  return 0;
}