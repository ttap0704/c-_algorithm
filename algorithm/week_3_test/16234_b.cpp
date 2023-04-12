#include <bits/stdc++.h>
using namespace std;

int N, L, R, a[54][54], visited[54][54], cnt = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

int dfs (int y, int x, int sum_val) {
  v.push_back({y, x});
  sum_val += a[y][x];
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;

    int gap = abs(a[y][x] - a[ny][nx]);
    if (L <= gap && gap <= R) {
      sum_val = dfs(ny, nx, sum_val);
    }
  }

  return sum_val;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    int no_cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] == 0) {
          v.clear();
          int sum_val = dfs(i, j, 0);

          if (v.size() > 1) {
            int avg = floor(sum_val / v.size());
            for (pair<int, int> i : v) {
              a[i.first][i.second] = avg;
            }
          } else {
            no_cnt++;
          }
        }
      }
    }

    if (no_cnt == N * N) {
      break;
    } else {
      cnt++;
    }
  }
  
  cout << cnt << "\n";

  return 0;
}