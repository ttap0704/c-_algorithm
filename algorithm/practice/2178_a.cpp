#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, a[104][104], visited[104][104];
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  queue<pair<int ,int>> q;
  q.push({0, 0});
  visited[0][0] = 1;

  int y, x;
  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || !a[ny][nx] || visited[ny][nx]) continue;
      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;
    }
  }

  cout << visited[N - 1][M - 1] << '\n';

  return 0;
}