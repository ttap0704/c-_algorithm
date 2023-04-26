#include <bits/stdc++.h>
using namespace std;

int N, from, to, ret = 1;
vector<pair<int, int>> v;


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> from >> to;
    
    v.push_back({to, from});
  }

  sort(v.begin(), v.end());

  from = v[0].second;
  to = v[0].first;

  for (int i = 1; i < N; i++) {
    if (v[i].second < to) continue;
    from = v[i].second;
    to = v[i].first;
    ret++;
  }

  cout << ret << '\n';

  return 0;
}