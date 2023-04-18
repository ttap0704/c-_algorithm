#include <bits/stdc++.h>
using namespace std;

int N, M, a[1504][1504], visited_w[1504][1504], visited_s[1504][1504], turn = 0;
queue<pair<int, int>> wq, sq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      
      if (a[i][j] == '.' || a[i][j] == 'L') {
        wq.push({i, j});
      }
      if (a[i][j] == 'L' && sq.size() == 0) sq.push({i, j});
    }
  }
  return 0;
}