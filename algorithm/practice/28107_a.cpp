#include <bits/stdc++.h>
using namespace std;

int N, M, n, m, a[100004];
priority_queue<int, vector<int>, greater<int>> pq[200004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> m;
      pq[m].push(i);
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> n;

    if (pq[n].size()) {
      a[pq[n].top()]++;
      pq[n].pop();
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}