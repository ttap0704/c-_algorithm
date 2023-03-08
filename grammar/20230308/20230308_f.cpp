// 랜덤 접근
// vector, Array와 같은 배열은 랜덥접근이 가능하여,
// k번째 요소에 접근할 때 O(1)이 걸림

// 순차적 접근
// 연결리스트, 스택, 큐는 순차적 접근만 가능하여,
// k번째 요소에 접근할 때 O(K)이 걸림

#include <bits/stdc++.h>
using namespace std;

list<int> a;

void print(list <int> a){
  for(auto it : a) cout << it << " ";
  cout << '\n';
}

int main () {
  for(int i = 1; i <= 3; i++) a.push_back(i); 
  for(int i = 1; i <= 3; i++) a.push_front(i);

  auto it = a.begin(); 
  it++;
  a.insert(it, 1000);
  print(a);

  it = a.begin();
  it++;
  a.erase(it);
  print(a);

  a.pop_front();
  a.pop_back();
  print(a);

  cout << a.front() << " : " << a.back() << "\n";

  a.clear();
  return 0;
}