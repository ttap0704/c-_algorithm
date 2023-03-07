// &연산자를 통해 메모리 주소의 첫번째를 출력
// i에 다른값을 할당해도 메모리 주소는 변하지 않음

#include <bits/stdc++.h>
using namespace std;

int i;
int main () {
  cout << &i << "\n";

  i = 0;
  
  cout << &i << "\n";
  return 0;
}