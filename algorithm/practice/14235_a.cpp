#include <bits/stdc++.h>
using namespace std;

int T, n;
priority_queue<int> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 0) {
      if (pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << -1 << '\n';
      }
    } else {
      int mx = n;
      for (int i = 0; i < mx; i++) {
        cin >> n;
        pq.push(n);
      }
    }
  }

  return 0;
}