// int 최대값에 +1을하면
// int 최소값으로 바뀜

// 위와 반대로도 됨

#include <bits/stdc++.h>
using namespace std;

int main () {
  int a = 2147483647; 
  cout << a << '\n'; 

  a++;
  cout << a << '\n';

  int b = -2147483648; 
  cout << b << '\n'; 
  
  b--;
  cout << b << '\n';
}