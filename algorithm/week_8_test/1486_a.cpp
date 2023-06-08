#include <bits/stdc++.h>
using namespace std;

struct San {
  int y, x, ti;
};
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, T, D, a[26][26], visited[26][26], ret;
char c;

int calc (int y, int x, int ny, int nx) {
  // return (int)pow(a[ny][nx] - a[y][x], 2) + 1;
  if (a[ny][nx] > a[y][x]) {
    return (int)pow(a[ny][nx] - a[y][x], 2);
  } else {
    return 1;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> T >> D;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      if (tolower(c) != c) a[i][j] = (c - 'A');
      else a[i][j] = (c - 'a') + 26;
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  fill(&visited[0][0], &visited[25][26], INF);
  queue<San> q;
  q.push({0, 0, 0});
  visited[0][0] = 0;
  vector<San> v;
  bool flag = 0;

  while (true) {
    while (q.size()) {
      San san = q.front();
      q.pop();
      if (!flag && ret <= a[san.y][san.x]) {
        v.push_back(san);
        ret = a[san.y][san.x];
      }
      
      for (int i = 0; i < 4; i++) {
        int ny = san.y + dy[i];
        int nx = san.x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || san.ti + calc(san.y, san.x, ny, nx) > D || abs(a[ny][nx] - a[san.y][san.x]) > T) continue;
        if (visited[ny][nx] > san.ti + calc(san.y, san.x, ny, nx)) {
          visited[ny][nx] = san.ti + calc(san.y, san.x, ny, nx);
          q.push({ny, nx, san.ti + calc(san.y, san.x, ny, nx)});
        }
      }
    }

    flag = 1;
    if (v.size() && (visited[0][0] == 0 || visited[0][0] > D)) {
      San san = v.back();
      v.pop_back();
      ret = a[san.y][san.x];
      fill(&visited[0][0], &visited[25][26], INF);
      q.push(san);
      visited[san.y][san.x] = san.ti;
    } else {
      break;
    }
  }

  cout << ret << '\n';

  return 0;
}