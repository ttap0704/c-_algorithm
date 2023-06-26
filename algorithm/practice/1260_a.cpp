#include <bits/stdc++.h>
using namespace std;

int N, M, V, y, x, last;
priority_queue<int, vector<int>, greater<int>> adj[1004], adj2[1004];
vector<int> v;
int visited[1004];

void dfs (int here) {
  v.push_back(here);
  visited[here] = 1;

  while (adj[here].size()) {
    int there = adj[here].top();;
    adj[here].pop();
    if (visited[there]) continue;
    dfs(there);
  }
}

void bfs (int here) {
  queue<int> q;
  q.push(here);
  visited[here] = 1;
  v.push_back(here);

  while (q.size()) {
    int h = q.front();
    q.pop();
    
    while (adj2[h].size()) {
      int there = adj2[h].top();
      adj2[h].pop();
      if (visited[there]) continue;

      visited[there] = 1;
      v.push_back(there);
      q.push(there);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    adj[y].push(x);
    adj[x].push(y);
    adj2[y].push(x);
    adj2[x].push(y);
  }

  dfs(V);
  for (int i : v) cout << i << ' ';
  cout << '\n';

  memset(visited, 0, sizeof(visited));
  v.clear();

  bfs(V);
  for (int i : v) cout << i << ' ';
  cout << '\n';

  return 0;
}