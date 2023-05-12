#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, B, sum, avg, p, m, a[504][504], ret = 1e9, ret2 = 0, mx = -1e9;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> B;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int avg = 0; avg <= 256; avg++) {
    m = 0;
    p = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (a[i][j] > avg) {
          m += a[i][j] - avg;
        } else if (a[i][j] < avg) {
          p += abs(a[i][j] - avg);
        }
      }
    }

    if (m + B >= p) {
      if (ret >= ((m * 2) + p)) {
        ret = (m * 2) + p;
        ret2 = avg;
      }
    }
  }

  cout << ret << ' ' << ret2 << '\n';

  return 0;
}