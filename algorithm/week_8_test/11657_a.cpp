#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, a, b, c, dist[1004];
vector<pair<int, int>> adj[1004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  fill(dist, dist + N + 1, INF);
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
  }

  dist[0] = 0;
  queue<int> q;
  for (int i = 0; i < N; i++) {
    for (int here = 0; here < N; here++) {
      for (pair<int, int> there : adj[here]) {
        int to = there.first;
        int d = there.second;

        if (dist[here] != INF && dist[here] + d < dist[to]) {
          if (i == N - 1) q.push(to);
          dist[to] = dist[here] + d;
        }
      }
    }
  }

  if (q.size()) cout << -1 << '\n';
  else {
    for (int i = 1; i < N; i++) {
      cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
  }

  return 0;
}