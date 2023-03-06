// double을 int로 형번환

// double > double , int > int로 계산하고 형변환 하기

#include <bits/stdc++.h>
using namespace std;

int main () {
  double ret = 2.12345;
  int n = 1;
  int a = (int)round(ret / double(n));
  cout << a << "\n";

  int test = 3;
  double n2 = 3.12345;
  double b = (double)round(test / int(n2));
  cout << b << "\n";

  return 0;
}