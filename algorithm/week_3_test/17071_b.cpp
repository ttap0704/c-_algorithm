#include <bits/stdc++.h>
using namespace std;

int N, K = 0, visited[2][500004], turn = 1, ret = 0;

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

    if (K > 500000) {
      ret = -1;
      break;
    }

    if (visited[turn % 2][K]) {
      ret = turn;
      flag = 1;
      break;
    }

    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      int x = q.front();
      q.pop();

      vector<int> nx_v = {x + 1, x - 1, x * 2};
      for (int nx : nx_v) {
        if (flag) break;
        if (nx < 0 || nx > 500000 || visited[turn % 2][nx]) continue;
        if (nx == K) {
          ret = turn;
          flag = 1;
          break;
        }
        visited[turn % 2][nx] = turn + 1;
        q.push(nx);
      }
      if (flag) break;
    }

    if (flag) break;
    turn++;
  }

  if (flag) cout << ret << "\n";
  else cout << -1 << "\n";

  return 0;
}