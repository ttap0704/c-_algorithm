#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 1e8;
char a[11][11];

void makeBoard (int idx, char b[11][11]) {
  if (idx == 0) {
    for (int i = 0; i < N; i++) {
      int l = 0;
      bool flag = 0;
      for (int j = 0; j < M; j++) {
        if (b[i][j] == '#') l = j + 1, flag = 0;
        else if (b[i][j] == 'O') flag = 1;
        else if (b[i][j] == 'R' || b[i][j] == 'B') {
          if (!flag) {
            b[i][l] = b[i][j];
            if(j != l) b[i][j] = '.';
            l += 1;
          } else {
            b[i][j] = '.';
          }
        }
      }
    }
  } else if (idx == 1) {
    for (int i = 0; i < N; i++) {
      int l = 0;
      bool flag = 0;
      for (int j = M - 1; j >= 0; j--) {
        if (b[i][j] == '#') l = j - 1, flag = 0;
        else if (b[i][j] == 'O') flag = 1;
        else if (b[i][j] == 'R' || b[i][j] == 'B') {
          if (!flag) {
            b[i][l] = b[i][j];
            if(j != l) b[i][j] = '.';
            l -= 1;
          } else {
            b[i][j] = '.';
          }
        }
      }
    }
  } else if (idx == 2) {
    for (int j = 0; j < M; j++) {
      int l = 0;
      bool flag = 0;
      for (int i = 0; i < N; i++) {
        if (b[i][j] == '#') l = i + 1, flag = 0;
        else if (b[i][j] == 'O') flag = 1;
        else if (b[i][j] == 'R' || b[i][j] == 'B') {
          if (!flag) {
            b[l][j] = b[i][j];
            if(i != l) b[i][j] = '.';
            l += 1;
          } else {
            b[i][j] = '.';
          }
        }
      }
    }
  } else if (idx == 3) {
    for (int j = 0; j < M; j++) {
      int l = 0;
      bool flag = 0;
      for (int i = N - 1; i >= 0; i--) {
        if (b[i][j] == '#') l = i - 1, flag = 0;
        else if (b[i][j] == 'O') flag = 1;
        else if (b[i][j] == 'R' || b[i][j] == 'B') {
          if (!flag) {
            b[l][j] = b[i][j];
            if(i != l) b[i][j] = '.';
            l -= 1;
          } else {
            b[i][j] = '.';
          }
        }
      }
    }
  }
}

void go (int cnt, char b[11][11], int before) {
  if (cnt >= 10) {
    return;
  }

  char c[11][11];
  for (int t = 0; t < 4; t++) {
    if (t == before) continue;
    memcpy(c, b, sizeof(c));
    makeBoard(t, c);

    int r_cnt = 0, b_cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (c[i][j] == 'R') r_cnt++;
        else if (c[i][j] == 'B') b_cnt++;
      }
    }
    if (r_cnt == 0 && b_cnt == 1) {
      ret = min(cnt + 1, ret);
    }
    go(cnt + 1, c, t);
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

  go(0, a, -1);

  if (ret == 1e8) cout << -1 << '\n';
  else cout << ret << '\n';

  return 0;
}