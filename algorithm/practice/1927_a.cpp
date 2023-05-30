#include <bits/stdc++.h>
using namespace std;

int T, N;
priority_queue<int, vector<int>, greater<int>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    if (N == 0) {
      if (pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << 0 << '\n';
      }
    } else {
      pq.push(N);
    }
  }

  return 0;
}