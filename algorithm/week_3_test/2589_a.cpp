#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[54][54], visited[54][54];
char c;

void bfs (int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});
  
  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] || visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

int checkVisited() {
  int mx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      mx = max(mx, visited[i][j]);
    }
  }

  return mx;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      if (c == 'W') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }

  int mx = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j]) continue;

      fill(&visited[0][0], &visited[53][54], 0);
      bfs(i, j);
      mx = max(mx, checkVisited());
    }
  }

  cout << mx - 1<< "\n";
  return 0;
}