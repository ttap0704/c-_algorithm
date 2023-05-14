#include <bits/stdc++.h>
using namespace std;

int N, M, ret = -1e9, a[504][504];

int techOne (int y, int x) {
  int mx = -1e9;

  for (int t = 0; t < 2; t++) {
    int ny = y, nx = x;

    int sum = 0;
    for (int i = 0; i < 4; i++) {
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
        sum = 0;
        break;
      }

      sum += a[ny][nx];
      
      if (t == 0) ny++;
      else nx++;
    }

    mx = max(mx, sum);
  }

  return mx;
}

int techTwo (int y, int x) {
  if (y + 1 >= N || x + 1 >= M) return 0;
  return a[y][x] + a[y + 1][x] + a[y][x + 1] + a[y + 1][x + 1];
}

int techThree (int y, int x) {
  int mx = -1e9;
  if (y + 2 < N) {
    int sum = a[y][x] + a[y + 1][x] + a[y + 2][x];

    for (int i = 0; i < 4; i++) {
      int plus_y = i < 2 ? 0 : 2;
      int plus_x = i % 2 == 1 ? 1 : -1;
      int ny = y + plus_y;
      int nx = x + plus_x;
      
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

      mx = max(mx, sum + a[ny][nx]);
    }
  }

  if (x + 2 < M) {
    int sum = a[y][x] + a[y][x + 1] + a[y][x + 2];

    for (int i = 0; i < 4; i++) {
      int plus_y = i % 2 == 1 ? 1 : -1;
      int plus_x = i < 2 ? 0 : 2;
      int ny = y + plus_y;
      int nx = x + plus_x;
      
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

      mx = max(mx, sum + a[ny][nx]);
    }
  }

  return mx;
}

int techFour (int y, int x) {
  int mx = -1e9;
  if (y + 1 < N) {
    int sum = a[y][x] + a[y + 1][x];

    for (int i = 0; i < 2; i++) {
      int ny1 = i == 0 ? y : y + 1;
      int nx1 = x + 1;
      int ny2 = i == 0 ? y + 1 : y;
      int nx2 = x - 1;

      if (nx1 < 0 || nx1 >= M || nx2 < 0 || nx2 >= M) continue;

      mx = max(mx, sum + a[ny1][nx1] + a[ny2][nx2]);
    }
  }

  if (x + 1 < M) {
    int sum = a[y][x] + a[y][x + 1];

    for (int i = 0; i < 4; i++) {
      int ny1 = y + 1;
      int nx1 = i == 0 ? x : x + 1;
      int ny2 = y - 1;
      int nx2 = i == 0 ? x + 1 : x;
      
      if (ny1 < 0 || ny1 >= N || ny2 < 0 || ny2 >= N) continue;

      mx = max(mx, sum + a[ny1][nx1] + a[ny2][nx2]);
    }
  }

  return mx;
}

int techFive (int y, int x) {
  int mx = -1e9;
  if (y + 2 < N) {
    int sum = a[y][x] + a[y + 1][x] + a[y + 2][x];

    for (int i = 0; i < 2; i++) {
      int ny = y + 1;
      int nx = i == 0 ? x + 1 : x - 1;
      
      if (nx < 0 || nx >= M) continue;

      mx = max(mx, sum + a[ny][nx]);
    }
  }

  if (x + 2 < M) {
    int sum = a[y][x] + a[y][x + 1] + a[y][x + 2];

    for (int i = 0; i < 2; i++) {
      int ny = i == 0 ? y + 1 : y - 1;
      int nx = x + 1;
      
      if (ny < 0 || ny >= N) continue;

      mx = max(mx, sum + a[ny][nx]);
    }
  }

  return mx;
}

void check (int y, int x) {
  ret = max(ret, techOne(y, x));
  ret = max(ret, techTwo(y, x));
  ret = max(ret, techThree(y, x));
  ret = max(ret, techFour(y, x));
  ret = max(ret, techFive(y, x));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      check(i, j);
    }
  }

  cout << ret << '\n';

  return 0;
}