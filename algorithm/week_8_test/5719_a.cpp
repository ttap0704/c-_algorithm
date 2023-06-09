#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, S, D, u, v, p, dist[504], a[504][504];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void move () {
  fill(dist, dist + 504, INF);
  pq.push({0, S});
  dist[S] = 0;

  while (pq.size()) {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (dist[here] != here_dist) continue;
    for (int i = 0; i < N; i++) {
      int _dist = a[here][i];
      if (_dist == -1) continue;
      if (dist[i] > dist[here] + _dist) {
        dist[i] = dist[here] + _dist;
        pq.push({dist[i], i});
      }
    }
  }
}

void eraeeEdge () {
  queue<int> q;
  q.push(D);

  while (q.size()) {
    int d = q.front();
    q.pop();
    for (int i = 0; i < N; i++) {
      if (dist[d] == dist[i] + a[i][d] && a[i][d] != -1) {
        a[i][d] = -1;
        q.push(i);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    cin >> S >> D;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < M; i++) {
      cin >> u >> v >> p;
      a[u][v] = p;
    }

    move();
    eraeeEdge();
    move();
    cout << (dist[D] == INF ? -1 : dist[D]) << '\n';
  }

  return 0;
}