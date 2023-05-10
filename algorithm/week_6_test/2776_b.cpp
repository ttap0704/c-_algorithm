#include <bits/stdc++.h>
using namespace std;

int T, N, M, n;

int check (int n, vector<int> &v) {
  int lo = 0, hi = v.size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (v[mid] == n) return 1;
    else if (v[mid] > n) hi = mid - 1;
    else lo = mid + 1;
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
    vector<int> v;
    for (int i = 0; i < N; i++) cin >> n, v.push_back(n);
    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> n;
      cout << check(n, v) << '\n';
    }
  }

  return 0;
}