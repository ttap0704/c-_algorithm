// 변수의 메모리 주소를 담는 타입이 "포인터"
// "포인터"는 메모리 동적할당, 데이터를 복사하지 않고 매개변수로 사용, 
// 클래스 및 구조체를 연결할 때 사용

// <타입> * 형태로 포인터를 정의
// c++ 에서 * 은 에스터리스크 라고 불림

// 포인터의 크기는
// 32bit -> 4byte
// 64bit -> 8byte
// 로 고정되어있음


#include <bits/stdc++.h>
using namespace std;

int i;
string s = "leedg";
int main () {
  i = 0;
  int * a = &i;
  cout << a << "\n";

  string * b = &s;
  cout << b << "\n";
  
  return 0;
}