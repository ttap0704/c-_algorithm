#include <bits/stdc++.h>
using namespace std;

int T, n, m, p;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> n;

    if (pq.size()) {
      if (pq.top() <= n) {
        pq2.push(n);
      } else {
        pq.push(n);
      }
    } else {
      pq.push(n);
    }

    if (pq.size() + 1 < pq2.size()) {
      pq.push(pq2.top());
      pq2.pop();
    } else if (pq2.size() + 1 < pq.size()) {
      pq2.push(pq.top());
      pq.pop();
    }

    if (pq2.size() > pq.size()) {
      cout << pq2.top() << '\n';
    } else {
      cout << pq.top() << '\n';
    }
  }

  return 0;
}