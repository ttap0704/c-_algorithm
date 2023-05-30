#include <bits/stdc++.h>
using namespace std;

int N, n;
priority_queue<int, vector<int>, greater<int>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N * N; i++) {
    cin >> n;

    pq.push(n);

    while (pq.size() > N) {
      pq.pop();
    }
  }

  cout << pq.top() << '\n';

  return 0;
}