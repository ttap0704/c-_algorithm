#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int a[10][10], ret = INF;
map<int,int> papers;

void setVisited(int y, int x, int num, int val) {
  for (int i = y; i < y + num; i++) {
    for (int j = x; j < x + num; j++) {
      a[i][j] = val;
    }
  }
}

bool check (int y, int x, int num) {
  if (y + num > 10 || x + num > 10) return false;
  for (int i = y; i < y + num; i++) {
    for (int j = x; j < x + num; j++) {
      if (a[i][j] != 1) return false;
    }
  }

  return true;
}

void go (int y, int x, int cnt) {
  if (cnt == ret) return;
  if (x == 10) {
    go (y + 1, 0, cnt);
    return;
  }
  if (y == 10) {
    ret = min(ret, cnt);
  }

  if (a[y][x] != 1) {
    go(y, x + 1, cnt);
    return;
  }
  
  for (int i = 5; i >= 1; i--) {
    if (papers[i] >= 5) continue;
    if (check(y, x, i)) {
      papers[i]++;
      setVisited(y, x, i, 2);
      go(y, x + i, cnt + 1);
      setVisited(y, x, i, 1);
      papers[i]--;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> a[i][j];
    }
  }

  go(0, 0, 0);

  if (ret == INF) {
    cout << -1 << '\n';
  } else {
    cout << ret << '\n';
  }

  return 0;
}