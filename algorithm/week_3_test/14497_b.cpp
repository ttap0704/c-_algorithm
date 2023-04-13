#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, _y1, _x1, _y2, _x2, visited[304][304], turn = 1;
char a[304][304];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  cin >> _y1 >> _x1 >> _y2 >> _x2;

  fill(&a[0][0], &a[303][304], '1');
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }

  queue<pair<int, int>> q;
  q.push({_y1, _x1});
  visited[_y1][_x1] = 1;

  int y, x;

  while (a[_y2][_x2] != '0') {
    queue<pair<int, int>> q2;

    while (q.size()) {
      tie(y, x) = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx]) continue;
        visited[ny][nx] = turn;
        
        if (a[ny][nx] != '0') {
          q2.push({ny, nx});
          a[ny][nx] = '0';
        } else {
          q.push({ny, nx});
        }
      }
    }

    q = q2;
    turn++;
  }

  cout << turn - 1 << "\n";

  return 0;
}