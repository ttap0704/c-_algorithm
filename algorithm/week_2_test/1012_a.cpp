#include <bits/stdc++.h>
using namespace std;

int T, M, N, K, X, Y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    int ret = 0;
    cin >> M >> N >> K;

    int a[M][N];
    int visited[M][N];

    fill(&a[0][0], &a[M - 1][N], 0);
    fill(&visited[0][0], &visited[M - 1][N], 0);
    for (int j = 0; j < K; j++) {
      cin >> X >> Y;
      a[X][Y] = 1;
    }

    for (int j = 0; j < M; j++) {
      for (int k = 0; k < N; k++) {
        if (a[j][k] == 1 && visited[j][k] == 0) {
          queue<pair<int, int>> q;
          q.push({j, k});
          visited[j][k] = 1;

          while (q.size()) {
            int y;
            int x;
            tie(y, x) = q.front();
            q.pop();

            for (int z = 0; z < 4; z++) {
              int ny = y + dy[z];
              int nx = x + dx[z];

              if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
              if (a[ny][nx] == 0) continue;
              if (visited[ny][nx] == 1) continue;
              visited[ny][nx] = 1;
              q.push({ny, nx});
            }
          }
          ret++;
        }
      }
    }

    cout << ret << "\n";
  }

  return 0;
}