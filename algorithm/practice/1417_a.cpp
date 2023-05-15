#include <bits/stdc++.h>
using namespace std;

int N, n, a, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  priority_queue<int> pq;

  for (int i = 0; i < N; i++) {
    cin >> n;
    if (i == 0) a = n;
    else pq.push(n);
  }

  while (pq.size() && pq.top() >= a) {
    int num = pq.top();
    pq.pop();
    num--;
    a++;
    ret++;

    pq.push(num);
  }

  cout << ret << '\n';

  return 0;
}