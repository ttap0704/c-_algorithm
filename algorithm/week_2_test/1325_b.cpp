#include <bits/stdc++.h>
using namespace std;

int N, M, visited[10004], cnt[10004], c, p, mx = 0;
vector<int> a[10004];

int dfs (int here) {
  visited[here] = 1;
  int ret = 1;

  for (int there : a[here]) {
    if (visited[there]) continue;
    ret += dfs(there);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> c >> p;
    a[p].push_back(c);
  }

  for (int i = 0; i <= N; i++) {
    fill(visited, visited + 10004, 0);
    int cur_cnt = dfs(i);
    mx = max(mx, cur_cnt);
    cnt[i] = cur_cnt;
  }

  for (int i = 0; i <= N; i++) {
    if (cnt[i] == mx) cout << i << " ";
  }

  return 0;
}