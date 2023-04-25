#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<pair<int, int>> v;

bool customSort (pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;

    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), customSort);

  for (pair<int, int> p : v) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}