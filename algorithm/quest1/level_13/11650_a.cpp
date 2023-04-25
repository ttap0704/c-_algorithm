#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<pair<int, int>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  for (pair<int, int> p : v) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}