#include <bits/stdc++.h>
using namespace std;

int N, M, X, y, x, ret, visited[100004];
vector<int> adj1[100004], adj2[100004];

int bfs (int here, vector<int> adj[100004]) {
  int ret = 0;
  queue<int> q;
  visited[here] = 1;
  q.push(here);

  while(q.size()) {
    int cur_here = q.front();
    q.pop();

    for (int there : adj[cur_here]) {
      if (visited[there]) continue;
      visited[there] = 1;
      q.push(there);
      ret++;
    }
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    adj1[y].push_back(x);
    adj2[x].push_back(y);
  }

  int ret1 = bfs(X, adj2);
  int ret2 = bfs(X, adj1);

  cout << ret1 + 1 << ' ' << N - ret2 <<  '\n';

  return 0;
}