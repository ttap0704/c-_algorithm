#include <bits/stdc++.h>
using namespace std;

int N, M, V, a, b;
priority_queue<int, vector<int>, greater<int>> adj[1004], adj2[1004];
bool visited[1004];

void dfs (int y) {
  if (visited[y]) return;

  cout << y << ' ';
  visited[y] = 1;;
  while (adj[y].size()) {
    int i = adj[y].top();
    adj[y].pop();

    if (visited[i]) continue;
    dfs(i);
  }
}

void bfs (int start) {
  queue<int> q;
  visited[start] = 1;
  q.push(start);

  while (q.size()) {
    int y = q.front();
    q.pop();

    cout << y << ' ';

    while (adj2[y].size()) {
      int i = adj2[y].top();
      adj2[y].pop();

      if (visited[i]) continue;
      visited[i] = 1;
      q.push(i);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    adj[a].push(b);
    adj[b].push(a);

    adj2[a].push(b);
    adj2[b].push(a);
  }

  dfs(V);
  cout << '\n';
  memset(visited, 0, sizeof(visited));
  bfs(V);
  cout << '\n';

  return 0;
}