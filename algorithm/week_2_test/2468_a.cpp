#include <bits/stdc++.h>
using namespace std;

int N, a[104][104], visited[104][104], ret = -1, cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs (int y, int x, int d) {
  visited[y][x] = 1;
  
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if (a[ny][nx] <= d) continue;
    if (visited[ny][nx] == 1) continue;
    dfs(ny, nx, d);
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

  
  for (int i = 0; i < 101; i++) {
    cnt = 0;
    fill(&visited[0][0], &visited[N - 1][N], 0);

    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (a[j][k] > i && visited[j][k] == 0) {
          dfs(j, k, i);
          cnt++;
        }
      }
    }

    ret = ret < cnt ? cnt : ret;
  }

  cout << ret << "\n";

  return 0;
}