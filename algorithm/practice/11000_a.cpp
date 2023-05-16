#include <bits/stdc++.h>
using namespace std;

int N, s, t, ret;
vector<pair<int, int>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> s >> t, v.push_back({s, t});
  sort(v.begin(), v.end());

  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(v[0].second);

  for (int i = 1; i < N; i++) {
    pq.push(v[i].second);

    if (pq.top() <= v[i].first) {
      pq.pop();
    }
  }
  
  cout << pq.size() << '\n';

  return 0;
}