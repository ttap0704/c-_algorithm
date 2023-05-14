#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> dq;

int main () { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) dq.push_back(i);

  while (dq.size()) {
    cout << dq.front() << ' ';
    dq.pop_front();

    if (dq.size()) {
      dq.push_back(dq.front());
      dq.pop_front();
    }
  }
  cout << '\n';

  return 0;
}