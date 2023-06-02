#include <bits/stdc++.h>
using namespace std;

int N, M, K, T, ti[304], dp[304][304], mx_ti, a, b;
vector<pair<int, int>> v;

int go (int here, int cnt, int before) {
  if (here == v.size()) return 0;

  int &ret = dp[here][cnt];
  if (ret) return ret;

  if (v[here].first >= T) before = 0;

  ret = max(ret, go(here + 1, cnt, before) + (v[here].first + before >= T ? v[here].second : 0));
  for (int i = 0; i <= cnt; i++) {
    if (v[here].first < T) ret = max(ret, go(here + 1, cnt - i, i + before) + (v[here].first + i + before >= T ? v[here].second : 0));
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K >> T;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;

    mx_ti = max(mx_ti, b);

    for (int i = a; i < b; i++) {
      ti[i]++;
    }
  }

  int prev = -1, cnt = 0;
  for (int i = 1; i <= mx_ti; i++) {
    if (prev == ti[i]) cnt++;
    else {
      if (prev != -1) v.push_back({prev, cnt});
      prev = ti[i];
      cnt = 1;
    }
  }

  cout << go(0, K, 0) << '\n';

  return 0;
}