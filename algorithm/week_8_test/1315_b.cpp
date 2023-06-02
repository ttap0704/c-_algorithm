#include <bits/stdc++.h>
using namespace std;

struct Quest {
  int st, in, pn;
};
vector<Quest> v;
int N, dp[1004][1004], a, b, c;
bool visited[54];

int go (int st, int in) {
  int &ret = dp[st][in];
  if (ret != -1) return ret;

  ret = 0;
  int pnt = 0;
  vector<int> idx;
  for (int i=  0; i < N; i++) {
    if (st < v[i].st && in < v[i].in) continue;
    ret++;
    if (!visited[i]) {
      visited[i] = 1;
      pnt += v[i].pn;
      idx.push_back(i);
    }
  }

  for (int i = 0; i <= pnt; i++) {
    int next_str = min(1000, st + i);
    int next_int = min(1000, in + (pnt - i));
    ret = max(ret, go(next_str, next_int));
  }

  for (int i : idx) visited[i] = 0;

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }

  memset(dp, -1, sizeof(dp));
  cout << go(1, 1) << '\n';

  return 0;
}