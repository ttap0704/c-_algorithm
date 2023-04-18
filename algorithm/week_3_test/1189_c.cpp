#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, K, visited[30][30], ret = 0;
char c[30][30];


void bfs(int y, int x) {
  if (y == 0 && x == M - 1) {
    if (visited[y][x] == K) {
      ret++;
    }
    return;
  }
  
      
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || c[ny][nx] != '.') continue;
    visited[ny][nx] = visited[y][x] + 1;
    bfs(ny, nx);
    visited[ny][nx] = 0;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c[i][j];
    }
  }

  visited[N - 1][0] = 1;
  bfs(N - 1, 0);

  cout << ret << "\n";
  return 0;
}