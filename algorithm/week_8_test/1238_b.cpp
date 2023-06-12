#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, X, a, b, c, dist1[1001], dist2[1001], ret = -INF;
vector<pair<int, int>> adj1[1001], adj2[1001];

void move(vector<pair<int, int>> *adj, int *dist) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, X});
  dist[X] = 0;

  while (pq.size()) {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (dist[here] != here_dist) continue;
    for (pair<int, int> p : adj[here]) {
      int there = p.second;
      int there_dist = p.first;

      if (dist[there] > dist[here] + there_dist) {
        dist[there] = dist[here] + there_dist;
        pq.push({dist[there], there});
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj1[a].push_back({c, b});
    adj2[b].push_back({c, a});
  }

  fill(dist1, dist1 + 1001, INF);
  fill(dist2, dist2 + 1001, INF);
  
  move(adj1, dist1);
  move(adj2, dist2);

  for (int i = 1; i <= N; i++) {
    ret = max(ret, dist1[i] + dist2[i]);
    // cout << "min : " << dist1[i] + dist2[i] << '\n';
  }

  cout << ret << '\n';

  return 0;
}