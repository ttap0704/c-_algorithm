#include <bits/stdc++.h>
using namespace std;

int N, M, a[104][104], visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs (int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;

  q.push({y, x});
  while(q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (a[ny][nx] == 0) continue;
      if (visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string num;
    cin >> num;
    
    for (int j = 0; j < num.size(); j++) {
      a[i][j] = int(num[j]) - 48;
    }
  }

  bfs(0, 0);
  cout << visited[N - 1][M - 1] << "\n";
  return 0;
}