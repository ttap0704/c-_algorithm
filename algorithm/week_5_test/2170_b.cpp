#include <bits/stdc++.h>
using namespace std;

int N, sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  vector<pair<int, int>> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());

  int from = v[0].first, to = v[0].second;
  for (pair<int, int> p : v) {
    if (from == p.first && to == p.second) continue;

    if (to >= p.first) {
      to = max(to, p.second);
    } else {
      sum += to - from;

      from = p.first;
      to = p.second;
    }
  }
  sum += to - from;

  cout << sum << '\n';

  return 0;
}