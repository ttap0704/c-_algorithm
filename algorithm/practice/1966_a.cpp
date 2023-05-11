#include <bits/stdc++.h>
using namespace std;

int T, N, M, n;

bool customSort (pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N >> M;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
      cin >> n;
      q.push({i, n});
      pq.push(n);
    }

    int cnt = 0;
    while (q.size()) {
      int idx = q.front().first;
      int val = q.front().second;
      q.pop();


      if (pq.top() == val) {
        pq.pop();
        cnt++;

        if (idx == M) {
          cout << cnt << '\n';
          break;
        }
      } else {
        q.push({idx, val});
      }
    }
  }

  return 0;
}