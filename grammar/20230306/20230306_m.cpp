// int
// 표현범위는 -2,147,483,648 ~ 2,147,483,647

// 예상값이 20억이 넘어간다면 long long 타입을 사용

// int 나누기 : 소수점 아래 모두 버림
// double : 소수점 아래 표기

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int INF = 987654321;
  const int INF2 = 1e9;

  cout << INF << '\n';
  cout << INF2 << '\n';

  int a = 3;
  int b = 2;
  cout << a / b << "\n";
  
  double c = 3;
  double d = 2;
  cout << c / d << "\n";

  return 0;
}