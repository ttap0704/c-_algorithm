#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
int N, K, visited[200004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  queue<int> q;
  q.push(N);
  visited[N] = 1;
  while (q.size()) {
    int here = q.front();;
    q.pop();

    if (here == K) {
      break;
    }

    vector<int> v = {here + 1, here - 1, here * 2};
    for (int there : v) {
      if (there < 0 || there > 100000 || visited[there]) continue;
      visited[there] = visited[here] + 1;
      q.push(there);
    }
  }

  cout << visited[K] - 1 << '\n';

  return 0;
}