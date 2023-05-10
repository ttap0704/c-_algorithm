#include <bits/stdc++.h>
using namespace std;

int N, n1, n2, ret, lis[104];
vector<pair<int, int>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n1 >> n2;
    v.push_back({n1, n2});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    auto pos = lower_bound(lis, lis + ret, v[i].second);
    if (*pos == 0) ret++;
    *pos = v[i].second;
  }

  cout << N - ret << '\n';

  return 0;
}