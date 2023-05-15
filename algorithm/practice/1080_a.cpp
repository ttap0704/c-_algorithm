#include <bits/stdc++.h>
using namespace std;

int N, M, a[54][54], b[54][54], ret;
char c;

void change (int y, int x) {
  for (int i = y; i <= y + 2; i++) {
    for (int j = x; j <= x + 2; j++) {
      a[i][j] = (a[i][j] + 1) % 2;
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
      cin >> c;
      a[i][j] = (c - '0');
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      b[i][j] = (c - '0');
    }
  }

  for (int i = 0; i < N - 2; i++) {
    for (int j = 0; j < M - 2; j++) {
      if (a[i][j] != b[i][j]) {
        change(i, j);
        ret++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] != b[i][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  cout << ret <<'\n';

  return 0;
}