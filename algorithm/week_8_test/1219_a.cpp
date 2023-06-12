#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = -1e9;
int N, S, E, M, x, y, z;
bool visited[54], flag;
ll a[54], dist[54];
vector<pair<int, int>> adj[54];
queue<int> q;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(dist, dist + 54, INF);

  cin >> N >> S >> E >> M;
  for (int i = 0; i < M; i++) {
    cin >> x >> y >> z;
    adj[x].push_back({z, y});
  }
  for (int i = 0; i < N; i++) cin >> a[i];

  dist[S] = a[S];
  for (int i = 0; i < N; i++) {
    for (int here = 0; here < N; here++) {
      for (pair<int, int> p : adj[here]) {
        int there = p.second;
        int there_dist = p.first;

        if (dist[here] != INF && dist[there] < dist[here] - there_dist + a[there]) {
          dist[there] = dist[here] - there_dist + a[there];
          if (i == N - 1) q.push(here);
        }
      }
    }
  }

  while (q.size()) {
    int here = q.front();
    q.pop();

    for (pair<int, int> p : adj[here]) {
      if (p.second == E) {
        flag = 1;
        break;
      }

      if (!visited[p.second]) {
        visited[p.second] = 1;
        q.push(p.second);
      }
    }
    
    if (flag) break;
  }

  if (dist[E] == INF) cout << "gg" << '\n';
  else if (flag) cout << "Gee" << '\n';
  else cout << dist[E] << '\n';

  return 0;
}