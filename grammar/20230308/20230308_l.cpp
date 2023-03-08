// queue는 먼저 넣은 데이터가 먼저 나오는 성질 (선입선출)
// 앞에서만 꺼낼 수 있읍

// deque는 앞뒤로 삽입/삭제/참조가 가능한 자료구조

#include <bits/stdc++.h>
using namespace std;

queue<int> q;
deque<int> dq;

int main () {
  for(int i = 1; i <= 10; i++)q.push(i); 
  while(q.size()) {
    cout << q.front() << ' ';
    q.pop(); 
  }
  cout << "\n";

  dq.push_front(1); 
  dq.push_back(2); 
  dq.push_back(3);
  cout << dq.front() << "\n"; 
  cout << dq.back() << "\n"; 
  cout << dq.size() << "\n"; 

  dq.pop_back(); 
  dq.pop_front();
  cout << dq.size() << "\n";

  return 0;
}