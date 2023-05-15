#include <bits/stdc++.h>
using namespace std;

int T, N, a, b;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    int ret = 0;
    vector<pair<int, int>> v;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a >> b, v.push_back({a, b});
    sort(v.begin(), v.end());

    int c = v[0].second;
    for (int i = 1; i < N; i++) {
      if (v[i].second > c) ret++;
      else c = v[i].second;
    }

    cout << N - ret << '\n';
  }

  return 0;
}