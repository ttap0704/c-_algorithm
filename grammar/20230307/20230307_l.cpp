// fill(시작값, 끝값, 초기화하는 값) : 0, 1 등 모든 숫자로 초기화 가능

#include <bits/stdc++.h>
using namespace std;

int a[10];
int b[10][10];

int main () {
  // fill(&a[0], &a[10], 100);
  cout << "a : " << a << "\n";
  fill(a,a + 10, 100); // 1차원의 경우 이것처럼 가능

  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";

  // fill(&b[0][0], &b[9][10], 2);
  cout << "b : " << b << "\n";
  fill(&b[0][0], &b[0][0] + 10 * 10, 2); // 2차원의 경우 이것처럼 가능
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){ 
      cout << b[i][j] << " ";
    }
    cout << '\n';
  }


  return 0;
}