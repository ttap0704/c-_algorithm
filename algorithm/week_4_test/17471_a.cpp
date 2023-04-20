#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, a[11], num, b, visited[11], mn = INF;
vector<int> v[11];

int dfs (int here) {
  visited[here] = 1;

  for (int i = 0; i < v[here].size(); i++) {
    int nx = v[here][i];
    int here_idx = (b & (1 << (here - 1)));
    int nx_idx = (b & (1 << (nx - 1)));
    if (visited[nx] || (nx_idx == 0 && here_idx != 0) || (nx_idx != 0 && here_idx == 0)) continue;
    dfs(nx);
  }

  return 1;
}

void go (int here) {
  if (here == N - 1) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
      if (visited[i]) continue;
      cnt += dfs(i);
    }

    if (cnt == 2) {
      int sum1 = 0;
      int sum2 = 0;
      for (int i = 1; i <= N; i++) {
        int idx = (b & (1 << (i - 1)));
        if (idx == 0) sum1 += a[i];
        else sum2 += a[i];
      }

      int total = abs(sum1 - sum2);
      mn = min(mn, total);
    } 
    return;
  }
  go(here + 1);
  b ^= (1 << here);
  go(here + 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  b = (1 << N) - 1;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= N; i++) {
    cin >> M;
    for (int j = 0; j < M; j++) {
      cin >> num;
      v[i].push_back(num);
    }
  }

  go(0);
  if (mn == INF) {
    cout << -1 << "\n";
  } else {
    cout << mn << "\n";
  }

  return 0;
}