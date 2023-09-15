#include <bits/stdc++.h>
using namespace std;

int N, a[9], mx = -1e9;
bool visited[9];
vector<int> v;

void solve () {
  if (v.size() == N) {
    int num = 0;
    for (int i = 0; i < N - 1; i++) {
      num += abs(v[i] - v[i + 1]);
    }

    mx = max(mx, num);
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    visited[i] = 1;
    v.push_back(a[i]);
    solve();
    v.pop_back();
    visited[i] = 0;
  }
} 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  solve();
  cout << mx << '\n';

  return 0;
}