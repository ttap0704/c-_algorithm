#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, n, dp[1004][3], ret = INF;
vector<int> a[1004];

int go (int here, int before) {
  if (here == N) return 0;

  int &ret = dp[here][before];
  if (ret != INF) return ret;
  
  for (int i = 0; i < 3; i++) {
    if (i == before) continue;
    ret = min(ret, go(here + 1, i) + a[here][i]);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> n, a[i].push_back(n);
    }
  }

  for (int i = 0; i < 3; i++) {
    fill(&dp[0][0], &dp[1003][3], INF);
    ret = min(ret, go(0, i));
  }

  cout << ret << '\n';

  return 0;
}