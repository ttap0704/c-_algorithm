#include <bits/stdc++.h>
using namespace std;

int N, M, n1, n2, d[32004];
vector<int> v[32004];
priority_queue<int, vector<int>, greater<int>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> n1 >> n2;
    d[n2]++;
    v[n1].push_back(n2);
  }

  for (int i = 1; i <= N; i++) {
    if (d[i] == 0) pq.push(i);
  }

  while (pq.size()) {
    int node = pq.top();
    pq.pop();

    cout << node << ' ';

    for (int i = 0; i < v[node].size(); i++) {
      int n_node = v[node][i];

      if (--d[n_node] == 0) pq.push(n_node);
    }
  }

  cout << '\n';

  return 0;
}