#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int> pq2;
priority_queue<int, vector<int>, less<int>> pq3;

struct Point {
  // 구조체의 멤버변수 설정
  int y, x;

  // y, x값을 받아 멤버변수를 생성한다는 의미
  // class의 constructor라는 메서드로 생각하면 됨
  Point(int y, int x) : y(y), x(x) {};

  // y, x값이 정해지지 않을 때 -1로 초기화
  Point(){y = -1; x = -1;};

  // 연산자 < 를 오버로딩
  bool operator < (const Point & a) const {
    // 최소를 가장먼저 꺼내고 싶을 때
    // return x > a.x;
    // 최대를 가장먼저 꺼내고 싶을 때
    return x < a.x;
  };
};
priority_queue<Point> pq4;

int main () {
  for(int i = 5; i >= 1; i--){
    pq.push(i); 
    pq2.push(i);
    pq3.push(i);
  }

  while(pq.size()){
    cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << '\n';
    pq.pop(); 
    pq2.pop(); 
    pq3.pop();
  }

  pq4.push({1, 1}); 
  pq4.push({2, 2}); 
  pq4.push({3, 3}); 
  pq4.push({4, 4}); 
  pq4.push({5, 5}); 
  pq4.push({6, 6});
  cout << pq4.top().x << "\n";

  return 0;
}