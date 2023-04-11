#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
map<int,int> papers;
int N = 10, a[11][11], ret = INF, draw_cnt = 0;

void handlePaper(int y, int x, int cnt, int value) {
  for (int i = y; i < y + cnt; i++) {
    for (int j = x; j < x + cnt; j++) {
      a[i][j] = value;
    }
  }
}

bool checkPaper(int y, int x, int cnt) {
  if (y + cnt > N || x + cnt > N) return false;
  for (int i = y; i < y + cnt; i++) {
    for (int j = x; j < x + cnt; j++) {
      if (a[i][j] != 1) return false;
    }
  }

  return true;
}

void go (int y, int x, int cnt) {
  if (cnt == ret) return;
  if (x == N) {
    go(y + 1, 0, cnt);
    return;
  }

  if (y == N) {
    ret = min(cnt, ret);
  }

  if (a[y][x] != 1) {
    go(y, x + 1, cnt);
  }

  for (int i = 5; i >= 1; i--) {
    if (papers[i] >= 5) continue;
    if (checkPaper(y, x, i)) {
      papers[i]++;
      handlePaper(y, x, i, 2);
      go(y, x + i, cnt + 1);
      handlePaper(y, x, i, 1);
      papers[i]--;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];

      if (a[i][j]) draw_cnt++;
    }
  }

  if (draw_cnt == 0) {
    cout << 0 << "\n";
    return 0;
  }

  go(0, 0, 0);
  if (ret == INF) {
    cout << -1 << "\n";
  } else {
    cout << ret << "\n";
  }

  return 0;
}