#include <bits/stdc++.h>
using namespace std;

int N, M, a[4][4], mx = 0;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for (int s = 0; s < (1 << (M * N)); s++) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
      int cur = 0;
      for (int j = 0; j < M; j++) {
        int k = j * N + i;
        if ((s & (1 << k)) == 0) {
          cur = cur * 10 + a[i][j];
        } else {
          sum += cur;
          cur = 0;
        }
      }

      sum += cur;
    }

    for (int j = 0; j < M; j++) {
      int cur = 0;
      for (int i = 0; i < N; i++) {
        int k = j * N + i;
        // cout << k << '\n';
        if ((s & (1 << k)) != 0) {
          cur = cur * 10 + a[i][j];
        } else {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    mx = max(mx, sum);
  }

  cout << mx << '\n';

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  return 0;
}