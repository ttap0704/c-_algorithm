#include <bits/stdc++.h>
using namespace std;

int N, sum = 0, a, b;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  set<int> v2;

  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({b, a});
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) {
      pq.pop();
    }
  }

  while (pq.size()) {
    sum += pq.top();
    pq.pop();
  }

  cout << sum << '\n';

  return 0;
}