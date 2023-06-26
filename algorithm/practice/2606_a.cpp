#include <bits/stdc++.h>
using namespace std;

int N, M, visited[104], y, x, ret = 1;
vector<int> adj[104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    adj[y].push_back(x);
    adj[x].push_back(y);
  }

  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (q.size()) {
    int here = q.front();
    q.pop();

    for (int there : adj[here]) {
      if (visited[there]) continue;
      visited[there] = ret;
      ret++;
      q.push(there);
    }
  }

  cout << ret - 1 << '\n';

  return 0;
}