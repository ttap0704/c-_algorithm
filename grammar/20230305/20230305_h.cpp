// cout으로 실수타입 출력하기

#include<bits/stdc++.h>
using namespace std; 
typedef long long ll; 
double a = 1.23456789; 

int main(){
  cout << a << "\n"; // 1.23457 
  cout.precision(7);
  cout << a << "\n"; // 1.234568 
  return 0;
}