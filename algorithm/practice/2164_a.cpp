#include <bits/stdc++.h>
using namespace std;

int N, cnt, a[2];
queue<int> q;


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  while (q.size() != 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }

  cout << q.front() << '\n';

  return 0;
}