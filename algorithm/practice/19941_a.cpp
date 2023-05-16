#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  queue<int> q, q2;
  for (int i = 0; i < N; i++) {
    cin >> c;
    while (q.size() && q.front() < i) q.pop();
    while (q2.size() && q2.front() < i) q2.pop();

    if (c == 'H') {
      if (q2.size() && q2.front() >= i) {
        q2.pop();
        ret++;
      } else {
        q.push(i + K);
      }
    } else {
      if (q.size() && q.front() >= i) {
        q.pop();
        ret++;
      } else {
        q2.push(i + K);
      }
    }
  }

  cout << ret << '\n';

  return 0;
}