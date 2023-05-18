#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6 + 4;
int N, dp[1000004];
vector<int> v;

void printTrace (int n) {
  cout << n << ' ';
  if (n % 3 == 0 && (dp[n] == (dp[n / 3] + 1))) printTrace(n / 3);
  else if (n % 2 == 0 && (dp[n] == (dp[n / 2] + 1))) printTrace(n / 2);
  else if (n - 1 && (dp[n] == (dp[n - 1] + 1))) printTrace(n - 1);
}

int go (int n, int calc) {
  if (n < 1) return INF;
  if (n == 1) return 0;

  int &ret = dp[n];
  if (ret != INF) return ret;

  if (n % 3 == 0) ret = min(ret, go(n / 3, 0) + 1);
  if (n % 2 == 0) ret = min(ret, go(n / 2, 1) + 1);
  ret = min(ret, go(n - 1, 2) + 1);

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;

  fill(&dp[0], &dp[1000003], INF);
  dp[1] = 0;
  cout << go(N, 0) << '\n';

  printTrace(N);
  cout << '\n';
  
  return 0;
}