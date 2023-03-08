// 스택은 가장 마지막으로 들어간 것이
// 가장 첫번째로 나옴 (후입선출)

// 재귀적인 함수, 알고리즘에 사용

// 삽입/삭제에는 O(1), 탐색에는 O(n)이 걸림
// n번째 요소를 찾는다고 가정하면, 앞에있는 요소부터 끄집어내는 과정을
// n번 반복해야하기 때문

#include <bits/stdc++.h>
using namespace std;

stack<string> stk;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stk.push("엄");
  stk.push("준");
  stk.push("식"); 
  stk.push("화");
  stk.push("이"); 
  stk.push("팅");

  while(stk.size()) {
    cout << stk.top() << "\n";
    stk.pop();
  }

  return 0;
}