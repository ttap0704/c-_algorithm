#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, M, C, dp[13][12][22], a[13], visited[22], ret;

int go (int idx, int back, int weight) {
  if (weight > C) return INF;
  if (idx == N) return 0;

  int &ret = dp[idx][back][weight];
  if (ret) return ret;

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    ret = max(ret, go(idx + 1, back, weight + a[i]) + 1);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> C;
  for (int i = 0; i < N; i++) cin >> a[i];

  for (int i = 0; i < M; i++) {
    int mx = go(0, i, 0);
    
    cout << mx << "\n";
    for (int j = ret; j < ret + mx; j++) {
      cout << i << " : " << j << '\n';
      visited[j] = 1;
    }
    ret += mx;
  }
  
  cout << ret << '\n';

  return 0;
}