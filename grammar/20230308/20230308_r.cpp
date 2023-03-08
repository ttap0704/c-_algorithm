#include <bits/stdc++.h>
using namespace std;

vector<int> v(3, 0); 

// 파라미터에 &를 붙혀
// 원본 vector의 값음 참조/수정
void go(vector<int> &v){
  v[1] = 100; 
}

int main(){ 
  go(v);
  for(int i : v) cout << i << '\n'; 
}