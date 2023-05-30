#include <bits/stdc++.h>
using namespace std;

int N, M, n, a[100004];
bool flag = 1;
priority_queue<int> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> n, pq.push(n);
  for (int i = 0; i < M; i++) cin >> a[i];

  for (int i = 0; i < N; i++) {
    if (pq.top() < a[i]) {
      flag = 0;
      break;
    }

    int r = pq.top() - a[i];
    pq.pop();
    if (r) pq.push(r);
  }

  if (flag) cout << 1 << '\n';
  else cout << 0 << '\n';

  return 0;
}