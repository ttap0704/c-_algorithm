#include <bits/stdc++.h>
using namespace std;

int N, L, a, b, ret, s;
deque<pair<int, int>> q;
int r = -1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    q.push_back({a, b});
  }
  sort(q.begin(), q.end());


  while (q.size()) {
    int s = q.front().first;
    int e = q.front().second;
    // cout << "s1 : " << s << '\n';
    // cout << (r >= s ? "있음" : "없음") << '\n';
    if (r >= s) {
      s = r;
    } else {
      s -= 1;
    }
    // cout << "s2 : " << s << '\n';
    while (s < e - 1) {
      ret++;
      s += L;
      // cout << "s3 : " << s << '\n';
    }
    r = s;
    // cout << r << '\n';
    q.pop_front();
  }

  cout << ret << '\n';

  return 0;
}