#include <bits/stdc++.h>
using namespace std;

int N, M, dp[1004][2][34], b[1004];

int go (int idx, int tree, int cnt) {
  if (cnt < 0) return -1e9;
  if (idx == N) return cnt == 0 ? 0 : -1e9;

  int &ret = dp[idx][tree][cnt];
  if (~ret) return ret;

  return ret = max(go(idx + 1, tree^1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> b[i];

  cout << max(go(0, 1, M - 1), go(0, 0, M)) << '\n'; 

  return 0;
}