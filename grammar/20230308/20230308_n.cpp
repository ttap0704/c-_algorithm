#include <bits/stdc++.h>
using namespace std;

struct Point {
  // 구조체의 멤버변수 설정
  int y, x;

  // y, x값을 받아 멤버변수를 생성한다는 의미
  // class의 constructor라는 메서드로 생각하면 됨
  Point(int y, int x) : y(y), x(x) {}

  // y, x값이 정해지지 않을 때 -1로 초기화
  Point(){y = -1; x = -1}

  // 연산자 < 를 오버로딩
  bool operator < (const Point & a) const {
    if(x == a.x) return < a.y;
    return x < a.x
  }
}


int main () {


  return 0;
}