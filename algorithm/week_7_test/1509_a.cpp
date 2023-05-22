#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string S;
int dp[2504][2504], dp2[2504];

int go (int here) {
  if (here == S.size()) return 0;
  int &ret = dp2[here];
  if (ret != INF) return ret;

  for (int i = 1; here + i <= S.size(); i++) {
    if(dp[here][i]) ret = min(ret, go(here + i) + 1);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    dp[i][1] = 1;
    if (i != S.size () - 1) {
      if (S[i] == S[i + 1]) dp[i][2] = 1;
    }
  }

  for (int _size = 3; _size <= S.size(); _size++) {
    for (int i = 0; i + _size <= S.size(); i++) {
      if(S[i] == S[i + _size - 1] && dp[i + 1][_size - 2]) dp[i][_size] = 1;
    }
  }

  fill(dp2, dp2 + 2504, INF);
  cout << go(0) << '\n';

  return 0;
}