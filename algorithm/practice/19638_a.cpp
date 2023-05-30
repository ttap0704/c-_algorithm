#include <bits/stdc++.h>
using namespace std;

int N, H, T, n;
priority_queue<int> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> H >> T;
  for (int i = 0; i < N; i++) cin >> n, pq.push(n);

  int bbyong = 0;
  while (pq.top() >= H && pq.top() != 1 && bbyong != T) {
    int t = pq.top() / 2;
    pq.pop();
    pq.push(t);

    bbyong++;
  }

  if (pq.top() < H) {
    cout << "YES" << '\n';
    cout << bbyong << '\n';
  } else {
    cout << "NO" << '\n';
    cout << pq.top() << '\n';
  }
  
  return 0;
}