#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<int> set;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  int j = v.size() - 1;
  for (int i = N; i >= 1; i--) {
    while (j >= 0 && v[j].first >= i) {
      pq.push(v[j].second);
      j--;
    }

    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
  }

  cout << ret << '\n';

  return 0;
}