#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, C, a[30], ret;
vector<int> v, v2;

void go (int here, int max_n, vector<int> &v, int sum) {
  if (sum > C) return;
  if (here > max_n) {
    v.push_back(sum);
    return;
  }

  go(here + 1, max_n, v, sum + a[here]);
  go(here + 1, max_n, v, sum);
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> a[i];

  go(0, N / 2 - 1, v, 0);
  go(N / 2, N - 1, v2, 0);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());

  for (int i : v) {
    if (C - i >= 0) ret += (int)(upper_bound(v2.begin(), v2.end(), C - i) - v2.begin());
  }

  cout << ret <<'\n';

  return 0;
}