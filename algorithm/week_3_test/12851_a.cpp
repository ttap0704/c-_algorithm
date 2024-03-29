#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, K, a[200004], visited[200004], cnt[200004], mn = INF;
vector<int> ny_arr;

void bfs(int y) {
  visited[y] = 1;
  cnt[y] = 1;
  queue<int> q;
  q.push(y);

  while (q.size()) {
    tie(y) = q.front();
    q.pop();

    for (int i = 0; i < 3; i++) {
      int ny = 0;
      if (i == 0) ny = y + 1;
      else if (i == 1) ny = y - 1;
      else if (i == 2) ny = y * 2;

      if (ny < 0 || ny > 200000) continue;
      if (visited[ny] == 0) {
        visited[ny] = visited[y] + 1;
        q.push(ny);
        cnt[ny] += cnt[y];
      } else if (visited[ny] == visited[y] + 1) {
        cnt[ny] += cnt[y];
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> K;
  if (N == K) {
    cout << 0 << "\n";
    cout << 1 << "\n";
    return 0;
  }
  bfs(N);

  cout << visited[K] - 1 << "\n";
  cout << cnt[K] << "\n";

  return 0;
}