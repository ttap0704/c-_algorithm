#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;

const int INF = 1e9;
int N, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp (int here, int visited) {
  if (visited == (1 << N) - 1) {
    return dist[here][0] ? dist[here][0] : INF;
  }

  int &ret = dp[here][visited];
  if (ret != -1) return ret;
  ret = INF;
  for (int i = 0; i < N; i++) {
    if (visited & (1 << i)) continue;
    if (dist[here][i] == 0) continue;
    ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
  }
  return ret;
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

  memset(dp, -1, sizeof(dp));
  cout << tsp(0, (1 << 0)) << '\n';

  return 0;
}