#include <bits/stdc++.h>
using namespace std;

// 벡터 정적할당
// 5개 요소를 담을 수있는 vector을 선언
// 모든 값을 100으로 채움
vector<int> v(5, 100);

// 직접 요소의 값을 입력해둠
vector<int> v2{10, 20, 30, 40, 50};

int main () {
  for(int a : v) cout << a << " "; cout << "\n";
  for(int a : v2) cout << a << " "; cout << "\n";
  return 0;
}