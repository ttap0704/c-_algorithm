#include <bits/stdc++.h>
using namespace std;

int N, K, a[104], visited[104], ret;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < K; i++) {
    if (!visited[a[i]]) {
      if (v.size() == N) {
        int last_idx = 0;
        int pos = 0;

        for (int _a : v) {
          int here_pick = 104;
          for (int j = i + 1; j < K; j++) {
            if (_a == a[j]) {
              here_pick = j;
              break;
            }
          }

          if (last_idx < here_pick) {
            last_idx = here_pick;
            pos = _a;
          }
        }

        visited[pos] = 0;
        ret++;
        v.erase(find(v.begin(), v.end(), pos));
      }

      v.push_back(a[i]);
      visited[a[i]] = 1;
    }
  }

  cout << ret << '\n';

  return 0;
}