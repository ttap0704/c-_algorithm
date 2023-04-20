#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, mx = 1;
char a[20][20];

void go (int y, int x, int num, int cnt) {
  mx = max(mx, cnt);

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    int _next = (1 << (int)(a[ny][nx] - 'A'));
    if ((num & _next) == 0) {
      go(ny, nx, num | _next, cnt + 1);
    }
  }
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

  go(0, 0, (1 << (int)(a[0][0] - 'A')), 1);
  cout << mx << '\n';

  return 0;
}