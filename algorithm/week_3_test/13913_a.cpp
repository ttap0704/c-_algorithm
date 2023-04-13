#include <bits/stdc++.h>
using namespace std;

int N, K, a[200004], visited[200004], prev_arr[200004];
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  if (N == K) {
    cout << 0 << "\n";
    cout << N << "\n";
    return 0;
  }

  visited[N] = 1;
  queue<int> q;
  q.push(N);

  int y = 0;
  while (q.size()) {
    tie(y) = q.front();
    q.pop();

    vector<int> ny_v = {y + 1, y - 1, y * 2};
    for (int ny : ny_v) {
      if (ny < 0 || ny > 200000) continue;
      if (visited[ny] == 0) {
        visited[ny] = visited[y] + 1;
        prev_arr[ny] = y;
        q.push(ny);
      }
    }
  }

  for (int i = K; i != N; i = prev_arr[i]) {
    v.push_back(i);
  }
  v.push_back(N);
  reverse(v.begin(), v.end());

  cout << visited[K] - 1 << "\n";
  for (int i : v) {
    cout << i << " ";
  }
  return 0;
}