// printf : string 형태는 
// str.c_str()을 통해 포인터(char *) 타입으로 변경해야함

#include <bits/stdc++.h>
using namespace std;

int a= 1;
char s = 'a';
string str = "어벤져스";
double b = 1.232325;

int main () {
  printf("아이엠 어 아이언맨 : %d\n%c\n", a, s);
  printf("아이엠 어 아이언맨 : %c\n", s);
  printf("아이엠 어 아이언맨 : %s\n", str.c_str());
  printf("아이엠 어 아이언맨 : %lf\n", b);
  return 0;
}