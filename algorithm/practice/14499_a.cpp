#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int N, M, T, dice[4][3], y, x, a[22][22], d;

void makeDice (int d) {
  if (d == 0) {
    int tmp = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = tmp;
  } else if (d == 1) {
    int tmp = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = dice[3][1];
    dice[3][1] = tmp;
  } else if (d == 2) {
    int tmp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp;
  } else if (d == 3) {
    int tmp = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = tmp;
  }

// cout << '\n';
//   for (int i = 0; i < 4; i++) {
//     for (int j = 0; j <3; j++) {
//       cout << dice[i][j] << ' ';
//     }
//     cout << '\n';
//   }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> y >> x >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  while (T--) {
    cin >> d;
    --d;

    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    makeDice(d);
    if (a[ny][nx] == 0) {
      a[ny][nx] = dice[3][1];
    } else {
      dice[3][1] = a[ny][nx];
      a[ny][nx] = 0;
    }

    y = ny;
    x = nx;

    cout << dice[1][1] << '\n';
  }

  return 0;
}