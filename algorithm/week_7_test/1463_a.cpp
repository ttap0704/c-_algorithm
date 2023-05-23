#include <bits/stdc++.h>
using namespace std;

int N, ret;
bool flag = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  queue<pair<int, int>> q;
  q.push({N, 0});
  
  while (q.size()) {
    int n = q.front().first;
    int cnt = q.front().second;

    if (n == 1) {
      ret = cnt;
      break;
    }

    q.pop();
    if (n % 3 == 0) q.push({n / 3, cnt + 1});
    if (n % 2 == 0) q.push({n / 2, cnt + 1});
    q.push({n - 1, cnt + 1});
  }
  
  cout << ret << '\n';

  return 0;
}