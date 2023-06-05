#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, dp[104][10][10][10][2], a[104], b[104];
char c;

int changeNumber(int x){
    return (x < 0) ? x + 10 : x % 10; 
}

int go (int here, int x, int y, int z, int flag) {
  if (here >= N) return 0;

  int &ret = dp[here][x][y][z][flag];
  if (ret != -1) return ret;

  if (changeNumber(x + a[here]) == changeNumber(b[here])) {
    return ret = min(go(here + 1, y, z, 0, 0), go(here + 1, y, z, 0, 1));
  }

  ret = INF;
  int _flag = flag ? 1 : -1;
  for (int i = 1; i <= 3; i++) {
    ret = min(ret, 1 + go(here, changeNumber(x + i * _flag), y, z, flag));
    ret = min(ret, 1 + go(here, changeNumber(x + i * _flag), changeNumber(y + i * _flag), z, flag));
    ret = min(ret, 1 + go(here, changeNumber(x + i * _flag), changeNumber(y + i * _flag), changeNumber(z + i * _flag), flag));
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> c, a[i] = (c - '0');
  for (int i = 0; i < N; i++) cin >> c, b[i] = (c - '0');
  

  memset(dp, -1, sizeof(dp));
  cout << min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)) << '\n';

  return 0;
}