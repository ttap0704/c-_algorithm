#include <bits/stdc++.h>
#define y1 asdasd
using namespace std;

int N, M, K, a[1025][1025], p_sum[1025][1025], y1, x1, y2, x2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
      p_sum[i][j] = a[i][j] + p_sum[i][j - 1];
    }
  }

  cin >> K;
  while (K--) {
    cin >> y1 >> x1 >> y2 >> x2;
    int sum = 0;
    for (int i = y1; i <= y2; i++) {
      sum += p_sum[i][x2] - p_sum[i][x1 - 1];
    }

    cout << sum << '\n';
  }

  return 0;
}