#include <bits/stdc++.h>
using namespace std;

int N, s, e, ret = 1;
vector<pair<int, int>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s >> e;
    v.push_back({e, s});
  }

  sort(v.begin(), v.end());

  e = v[0].first;
  s = v[0].second;
  for (int i = 1; i < v.size(); i++) {
    if (e <= v[i].second) {
      e = v[i].first;
      ret++;
    }
  }

  cout << ret << '\n';

  return 0;
}