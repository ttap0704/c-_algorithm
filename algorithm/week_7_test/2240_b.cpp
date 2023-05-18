#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int T, W, a[1004], dp[1004][34][3];

int go (int ti, int pos, int cnt) {
  if (cnt > W) {
    return INF;
  }

  if (ti == T) {
    return (a[ti] == pos ? 1 : 0);
  }

  int &ret = dp[ti][cnt][pos];
  if (ret) return ret;

  int next_pos = pos == 2 ? 1 : 2;
  ret = max(ret, max(go(ti + 1, next_pos, cnt + 1), go(ti + 1, pos, cnt)) + (a[ti] == pos));

  // cout << ti << " : " << pos << " : " << cnt << " ::: " << ret << '\n';

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T >> W;
  for (int i = 1; i <= T; i++) cin >> a[i];

  cout << max(go(0, 1, 0), go(0, 1, 1))  << '\n';

  return 0;
}