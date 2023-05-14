#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, y, x, d, a[54][54], ret;

bool check (int y, int x) {
  vector<int> v;
  
  for (int i = d + 1; i < d + 5; i++) {
    int ny = y + dy[i % 4];
    int nx = x + dx[i % 4];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] != 0) continue;
    v.push_back(i);
  }

  return v.size() > 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  cin >> y >> x >> d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    if (a[y][x] == 0) {
      ret++;
      a[y][x] = 2;
    }

    int ny, nx;
    if (!check(y, x)) {
      ny = y + dy[(d + 2) % 4];
      nx = x + dx[(d + 2) % 4];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 1) break;
    } else {
      while (true) {
        if (d == 0) d = 3;
        else d--;

        ny = y + dy[d];
        nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (a[ny][nx] == 0) break;
      }
    }

    y = ny;
    x = nx;
  }

  cout << ret << '\n';

  return 0;
}