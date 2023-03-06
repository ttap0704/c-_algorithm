// atoi : 입력받은 문자열이 숫자라면 숫자 / 문자라면 0을 반환

#include <bits/stdc++.h>
using namespace std;

int main () {
  string s = "5";
  string s2 = "amumu";

  cout << atoi(s.c_str()) << '\n';
  cout << atoi(s2.c_str()) << '\n';

  return 0;
}