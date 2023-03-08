#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main () {
  for (int i = 0; i <= 10; i++) v.push_back(i);
  for (int a : v) cout << a << " ";
  cout << "\n";
  
  v.pop_back();
  for (int a : v) cout << a << " ";
  cout << "\n";

  // 범위 내 벨류 지우기
  // 하나만 지울때는 시작값만
  v.erase(v.begin(), v.begin() + 3);
  for (int a : v) cout << a << " ";
  cout << "\n";

  auto a = find(v.begin(), v.end(), 100);
  if (a == v.end()) cout << "not fount v.end(): " << *v.end() << "\n";

  // 시작 끝 할당값 : 채우기
  fill(v.begin(), v.end(), 10);
  for (int a : v) cout << a << " ";
  cout << "\n";

  // 모든 값 지우기
  v.clear();
  cout << "아무것도 ?\n";
  for (int a : v) cout << a << " ";
  cout << "\n";


  return 0;
}