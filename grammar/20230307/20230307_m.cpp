// memset(배열 이름, 초기화 값, 배열의 크기)
// 0,-1,1,char형의 하나의 문자 등만으로 초기화 가능

#include <bits/stdc++.h>
using namespace std;

const int max_n = 1004;
int a[max_n];
int a2[max_n][max_n];

int main () {
  memset(a, -1, sizeof(a));
  memset(a2, 0, sizeof(a2));
  for(int i = 0; i < 10; i++) cout << a[i] << " "; 

  return 0;
}