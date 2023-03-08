#include <bits/stdc++.h>
using namespace std;

// 파라미터에 &를 붙히면
// 해당 값 참조가 되어 
// 원본의 값도 바뀌게 된다.
int add (int &a, int b) {
  a += 10;
  cout << a << "\n";
  return a + b;
}

int main () {
  int a = 1;
  int b = 2;
  add(a, b);

  cout << a << "\n";

  return 0;  
}

