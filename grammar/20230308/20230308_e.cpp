// 2차원 배열 탑색 빠르게 하는 팁

// 첫번째 차원 > 두번째 차원 순으로 탐색하는 것이 성능에 좋음
// c++에서는 캐시를 첫번째 차원 기준으로 하기 때문

#include <bits/stdc++.h>
using namespace std;

const int mxy = 3; 
const int mxx = 4;
int a[mxy][mxx];

int main () {
  for(int i = 0; i < mxy; i++){ 
    for(int j = 0; j < mxx; j++){
      a[i][j] = (i + j);
    }
  }

  // good
  for(int i = 0; i < mxy; i++){ 
    for(int j = 0; j < mxx; j++){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }

  // bad
  for(int i = 0; i < mxy; i++){ 
    for(int j = 0; j < mxx; j++){
      cout << a[j][i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}