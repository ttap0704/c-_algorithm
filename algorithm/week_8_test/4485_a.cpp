#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, a[130][130], dist[130][130], num = 1;
priority_queue<PI, vector<PI>, greater<PI>>pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> N;
    if (N == 0) break;

    fill(&a[0][0], &a[0][0] + (130 * 130), 0);
    fill(&dist[0][0], &dist[0][0] + (130 * 130), INF);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> a[i][j];
      }
    }

    pq.push({a[0][0], 0});
    dist[0][0] = a[0][0];
    while (pq.size()) {
      PI h = pq.top();
      int here_y = h.second / 1000;
      int here_x = h.second % 1000;
      int here_dist = h.first;
      pq.pop();

      if (dist[here_y][here_x] != here_dist) continue;
      for (int i = 0; i < 4; i++) {
        int there_y = here_y + dy[i];
        int there_x = here_x + dx[i];
        
        if (there_y < 0 || there_y >= N || there_x < 0 || there_x >= N) continue;
        if (dist[there_y][there_x] > dist[here_y][here_x] + a[there_y][there_x]) {
          dist[there_y][there_x] = dist[here_y][here_x] + a[there_y][there_x];
          pq.push({dist[there_y][there_x], (there_y * 1000 + there_x)});
        }
      }
    }

    cout << "Problem " << num << ": " << dist[N - 1][N - 1] << '\n';
    num++;
  }

  return 0;
}