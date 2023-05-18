#include <bits/stdc++.h>
#define MAX_N 18
using namespace std;

int N, a[MAX_N][MAX_N], dp[MAX_N][MAX_N][3];

bool check(int y, int x, int d){
  if (d == 0 || d == 2) {
    if(!a[y][x]) return true; 
  } else if (d == 1){
    if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true; 
  }
  return false; 
}

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

  dp[0][1][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

      if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

      if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
      if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
    }
  }

  int ret = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

  cout << ret << '\n';

  return 0;
}