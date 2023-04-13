#include <bits/stdc++.h>
using namespace std;

int N, K = 0, origin_k, visited[2][500004], turn = 1, ret = 0;

void calcCount (int cnt) {
  K = origin_k;
  for (int i = 1; i < cnt; i++) {
    K += i;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  
  if (N == K) {
    cout << 0 << "\n";
    return 0;
  }

  visited[0][N] = 1;
  queue<int> q;
  q.push(N);
  bool flag = 0;
  while (q.size()) {
    K += turn;

    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      int y = q.front();
      q.pop();

      if (K > 500000) break;
      if (visited[turn % 2][K]) {
        ret = turn;
        flag = 1;
        break;
      }

      vector<int> ny_v = {y + 1, y - 1, y * 2};
      for (int ny : ny_v) {
        if (flag) break;
        if (ny < 0 || ny > 500000 || visited[turn % 2][ny]) continue;
        visited[turn % 2][ny] = visited[turn % 2][y] + 1;
        if (ny == K) {
          ret = turn;
          flag = 1;
          break;
        }
        q.push(ny);
      }
    }

    if (flag) break;

    turn++;
  }

  if (flag) cout << ret << "\n";
  else cout << -1 << "\n";

  return 0;
}