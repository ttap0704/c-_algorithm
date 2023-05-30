#include <bits/stdc++.h>
using namespace std;

int N, M, K, v, c, ret = -1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    cin >> v >> c;
    pq.push({c, v});
  }

  int total = 0;
  while (pq.size()) {
    pair<int, int> p = pq.top();
    pq.pop();
    
    pq2.push(p.second);
    total += p.second;

    if (pq2.size() > N) {
      total -= pq2.top();
      pq2.pop();
    }

    if (pq2.size() == N && total >= M) {
      cout << p.first << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}