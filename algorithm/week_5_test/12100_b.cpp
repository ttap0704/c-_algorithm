#include <bits/stdc++.h>
using namespace std;

int N, ret = 0;
struct Board {
  int a[24][24];

  void rotate90 () {
    int tmp[24][24];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        tmp[i][j] = a[N - j - 1][i];
      }
    }
    memcpy(a, tmp, sizeof(a));
  }

  void move () {
    int tmp[24][24];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < N; i++) {
      int cnt = -1, b = 0;

      for (int j = 0; j< N; j++) {
        if (a[i][j] == 0) continue;

        if (b && a[i][j] == tmp[i][cnt]) tmp[i][cnt] *= 2, b = 0;
        else tmp[i][++cnt] = a[i][j], b = 1;
      }
    }

    memcpy(a, tmp, sizeof(a));
  }

  void getMax () {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        ret = max(ret, a[i][j]);
      }
    }
  }
};

void go (int cnt, Board b) {
  if (cnt == 5) {
    b.getMax();
    return;
  }

  for (int i = 0; i < 4; i++) {
    Board c;
    c = b;

    c.move();
    go(cnt + 1, c);
    b.rotate90();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  Board b;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> b.a[i][j];
    }
  }

  go(0, b);

  cout << ret << '\n';

  return 0;
}