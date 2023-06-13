#include <bits/stdc++.h>
using namespace std;

int N, M, a[100004], visited[100004], y, x;
bool flag;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    a[y]++; a[x]--;
  }

  for (int i = 1; i <= N; i++) {
    a[i] += i;
    visited[a[i]]++;
  }

  for (int i = 1; i <= N; i++) {
    if (visited[a[i]] > 1) flag = 1;
  }

  if (flag) cout << -1;
  else for (int i = 1; i <= N; i++) cout << a[i] << ' ';
  cout << '\n';

  return 0;
}