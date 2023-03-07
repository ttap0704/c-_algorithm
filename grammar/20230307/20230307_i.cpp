// 정적 메모리 할당
// BSS segment
// 전역변수, static, const로 선언되어있는 변수 중
// 0으로 초기화 되어있거나
// 어떠한 값으로도 초기화가 되어이씨 않은 변수들이
// BSS segment 메모리 영역에 할당 됨

#include <bits/stdc++.h>
using namespace std;

int a;
int b = 0;
int main () {
  static int d;
  static int e = 0;
  return 0;
}