#include <bits/stdc++.h>
using namespace std;

int N, M, a[100004], p_sum[100004], s, e;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    p_sum[i] = a[i] + p_sum[i - 1];
  }

  while (M--) {
    cin >> s >> e;
    cout << p_sum[e] - p_sum[s - 1] << '\n';
  }

  return 0;
}