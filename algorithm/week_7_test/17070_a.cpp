#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;

const int dy[] = {0, 1, 0, 1};
const int dx[] = {0, 0, 1, 1};
int N, a[MAX_N][MAX_N], ret;

void go (int y, int x, int s) {
  if (y == N - 1 && x == N - 1) {
    ret++;
  }

  for (int i = 1; i < 4; i++) {
    if (i == s) continue;

    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx]) continue;
    if (i == 3) {
      bool flag = 0;
      for (int j = 1; j <= 2; j++) {
        int ny2 = y + dy[j];
        int nx2 = x + dx[j];
        if (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= N || a[ny2][nx2]) {
          flag = 1;
          break;
        };
      }

      if (flag) break;
    }
    int tmp_s = 0;
    if (i == 1) tmp_s = 2;
    else if (i == 2) tmp_s = 1;
    else tmp_s = 0;

    go(ny, nx, tmp_s);
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

  go(0, 1, 1);

  cout << ret << '\n';

  return 0;
}