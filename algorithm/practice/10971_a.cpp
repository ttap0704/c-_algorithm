#include <bits/stdc++.h>
using namespace std;

int N, dist[11][11], mn = 1e9, start;

void solve (int total, int before, int cnt, int visited) {
  if (cnt == N) {
    if (dist[before][start]) {
      mn = min(mn, total + dist[before][start]);
    }
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited & (1 << i) || !dist[before][i]) continue;

    solve(total + dist[before][i], i, cnt + 1, visited | (1 << i));
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> dist[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    start = i;
    solve(0, i, 1, (1 << i));
  }

  cout << mn << '\n';

  return 0;
}