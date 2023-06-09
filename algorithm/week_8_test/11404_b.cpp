#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, y, x, z, a[104][104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&a[0][0], &a[0][0] + (104 * 104), INF);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> y >> x >> z;
    a[y][x] = min(a[y][x], z);
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) cout << 0 << ' ';
      else cout << (a[i][j] == INF ? 0 : a[i][j]) << ' ';
    }
    cout << '\n';
  }

  return 0;
}