#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int dy[] = {0, 1};
const int dx[] = {1, 0};
int N, a[104][104];
ll dp[104][104];


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int d = 0; d < 2; d++) {
        int ny = i + (dy[d] * a[i][j]);
        int nx = j + (dx[d] * a[i][j]);
        if (dp[i][j] == 0 || (i == N - 1 && j == N - 1) || ny >= N || nx >= N) continue;

        dp[ny][nx] += dp[i][j];
      }
    }
  }

  cout << dp[N - 1][N - 1] << '\n';

  return 0;
}