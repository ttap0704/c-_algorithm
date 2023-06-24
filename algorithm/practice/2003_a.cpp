#include <bits/stdc++.h>
using namespace std;

int N, M, n, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  queue<int> q;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> n;
    
    sum += n;
    q.push(n);
    while (q.size() && sum >= M) {
      if (sum == M) ret++;
      sum -= q.front();
      q.pop();
    }
  }
  
  cout << ret << '\n';

  return 0;
}