// string 타입에서 reverse 함수는 지원하지 않음
// STL에서 지원하는 reverse를 사용

// reserve(시작, 끝)
// 원본 문자열도 바꿔버림

#include <bits/stdc++.h>
using namespace std;

int main () {
  string a = "It's hard to have a sore leg";
  reverse(a.begin(), a.end());
  cout << a << '\n';

  reverse(a.begin(), a.end());
  cout << a << '\n';

  reverse(a.begin() + 3, a.end());
  cout << a << '\n';

  return 0;
}