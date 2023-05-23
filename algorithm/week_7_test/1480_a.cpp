#include <bits/stdc++.h>
using namespace std;

int N, M, C, a[24], dp[24][1 << 14][24];

int go (int here, int visited, int weight) {
  if (here == M) return 0;
  
  int &ret = dp[here][visited][weight];
  if (ret) return ret;
  ret = max(ret, go(here + 1, visited, C));

  for (int i = 0; i < N; i++) {
    bool check1 = (1 << i) & visited;
    bool check2 = (weight - a[i])>= 0;
    
    if (!check1 && check2) ret = max(ret, go(here, visited | (1 << i), weight - a[i]) + 1);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> C;
  for (int i = 0; i < N; i++) cin >> a[i];

  cout << go(0, 0, C) << '\n';

  return 0;
}