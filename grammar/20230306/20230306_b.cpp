// void : return값이 없다.

#include <bits/stdc++.h>
using namespace std;

int ret = 1;

void a () {
  ret = 2;
  cout << ret << "\n";
  return;
}

int main () {
  a();
  return 0;
}