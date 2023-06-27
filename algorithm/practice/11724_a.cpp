#include <bits/stdc++.h>
using namespace std;

int N, M, n1, n2, ret;
vector<int> adj[1004];
bool visited[1004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  while (M--) {
    cin >> n1 >> n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
  }

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      queue<int> q;
      q.push(i);
      visited[i] = 1;

      while (q.size()) {
        int here = q.front();
        q.pop();
        
        for (int there : adj[here]) {
          if (visited[there]) continue;
          visited[there] = 1;
          q.push(there);
        }
      }

      ret++;
    }
  }

  cout << ret << '\n';

  return 0;
}