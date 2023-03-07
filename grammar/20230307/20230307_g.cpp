// * 연산자를 통해 역참조
// 해당 메모리 주소값을 기반으로 값을 꺼냄

#include <bits/stdc++.h>
using namespace std;

int main () {
  string a = "abcde";
  string * b = &a;

  cout << b << "\n";
  cout << *b << "\n";

  return 0;
}