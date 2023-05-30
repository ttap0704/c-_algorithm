#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M, n, price[104], cars[2004], park[2004];
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> q;
ll ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> price[i], pq.push(i);
  for (int i = 1; i <= M; i++) cin >> cars[i];
  
  for (int i = 0; i < M * 2; i++) {
    cin >> n;

    if (n > 0) {
      if (pq.size()) {
        ret += price[pq.top()] * cars[n];
        park[n] = pq.top();
        pq.pop();
      } else {
        q.push(n);
      }
    } else {
      n *= -1;
      pq.push(park[n]);

      if (q.size()) {
        ret += price[pq.top()] * cars[q.front()];
        park[q.front()] = pq.top();
        pq.pop();
        q.pop();
      }
    }
  }

  cout << ret << '\n';

  return 0;
}