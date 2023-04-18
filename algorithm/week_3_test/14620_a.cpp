#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, visited[12][12], a[12][12], ret = INF;

int handleVisited(int y, int x, int val) {
  visited[y][x] = val;
  int sum_val = a[y][x];

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    sum_val += a[ny][nx];
    visited[ny][nx] = val;
  }

  return sum_val;
}

bool check (int y, int x) {
  if (visited[y][x]) return false;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) return false;
  }

  return true;
}

void dfs(int cnt, int hap) {
  if (cnt == 3) {
    ret = min(ret, hap);
    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (check(i, j)) {
        dfs(cnt + 1, hap + handleVisited(i, j, 1));
        handleVisited(i, j, 0);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  dfs(0, 0);

  cout << ret << "\n";
  return 0;
}