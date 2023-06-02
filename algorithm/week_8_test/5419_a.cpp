#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, N, x, y;
vector<pair<int, int>> a;
vector<int> tree, b;

ll sum (int idx) {
  ll ret = 0;

  while (idx > 0) {
    ret += tree[idx];
    idx -= (idx & -idx);
  }

  return ret;
}

void update (int idx, int diff) {
  while (idx <= N) {
    tree[idx] += diff;
    idx += (idx & -idx);
  }
}

int findIndex (vector<int> &b, int val) {
  int lo = 0, hi = b.size() - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;

    if (b[mid] == val) return mid;
    else if (b[mid] < val) lo = mid + 1;
    else hi = mid - 1;
  }

  return 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    a.clear();
    b.clear();
    tree.clear();
    tree.resize(N + 1);
    for (int i = 0; i < N; i++) {
      cin >> x >> y;
      a.push_back({x, y * -1});
      b.push_back(y * -1);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    update(findIndex(b, a[0].second) + 1, 1);
    ll ret = 0;

    for (int i = 1; i < N; i++) {
      int idx = findIndex(b, a[i].second) + 1;
      ret += sum(idx);
      update(idx, 1);
    }

    cout << ret << '\n';
  }

  return 0;
}