#include <bits/stdc++.h>
using namespace std;

int N, T, y, x, a, b, ret;
vector<int> adj[104];
bool visited[104];
queue<pair<int, int>> q;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> y >> x;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  q.push({y, 0});
  visited[y] = 1;
  while (q.size()) {
    int start, cnt;
    tie(start, cnt) = q.front();
    q.pop();
    if (start == x) {
      ret = cnt;
      break;
    }

    for (int i : adj[start]) {
      if (visited[i]) continue;
      visited[i] = 1;
      q.push({i, cnt + 1});
    }
  }

  if (ret) cout << ret << '\n';
  else cout << -1 << '\n';

  return 0;
}