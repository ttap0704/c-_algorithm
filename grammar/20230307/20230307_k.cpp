// vector, map 등 각각 다르게 구현된 컨테이너들을 일반화된 이터레이터를 통해 쉽게 순회
// 바로 주소값을 반환하지 못하고 &*로 한단계 더 거쳐 반환 가능

// begin() : 컨테이너의 시작 위치를 반환
// end() : 컨테이너의 끝 다음 위치를 반환
// advance(iterator, cnt) : 해당 iterator를 cnt까지 증가

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main () {
  for (int i = 1; i <= 5; i++) v.push_back(i);

  for (int i = 0; i < 5; i++) {
    cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";
    cout << &*(v.begin() + i) << "\n";
  }

  for(auto it = v.begin(); it != v.end(); it++){ 
    cout << *it << ' ';
  }
  cout << '\n';

  for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    cout << *it << ' ';
  }
  auto it = v.begin(); 
  advance(it, 3); 
  cout << '\n';
  cout << *it << '\n';

  return 0;
}