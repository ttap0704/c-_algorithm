#include <bits/stdc++.h>
using namespace std;

int N, M, visited[10004], c, p, mx = 0, cnt;
vector<int> a[10004], v;

void dfs (int start, int &cur_cnt) {
  visited[start] = 1;

  for (int i : a[start]) {
    if (visited[i] == 0) {
      cur_cnt++;
      dfs(i, cur_cnt);
    };
  }
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

  for (int i = 0; i < N + 1; i++) {
    cnt = 0;
    fill(visited, visited + 10004, 0);
    dfs(i, cnt);
    v.push_back(cnt);
    mx = max(mx, cnt);
  }

  for (int i = 0; i < N + 1; i++) {
    if (v[i] == mx) {
      cout << i << " ";
    }
  }
  return 0;
}