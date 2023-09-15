#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;

int N, a, b, ret[100004];
vector<int> adj[100004];

void dfs(int start) {
  for (int i : adj[start]) {
    if (ret[i]) continue;
    ret[i] = start;
    dfs(i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ret[1] = 1;
  dfs(1);

  for (int i = 2; i <= N; i++) {
    cout << ret[i] << '\n';
  }

  return 0;
}