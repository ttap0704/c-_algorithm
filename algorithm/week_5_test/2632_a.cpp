#include <bits/stdc++.h>
using namespace std;

int N, A, B, p, ret, _size[2][1004];
vector<int> adj[2][1004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> A >> B;
  
  for (int i = 0; i < A; i++) {
    cin >> p;
    if (p == N) ret++;
    if (i != A - 1) {
      adj[0][i].push_back(i + 1);
    } else {
      adj[0][i].push_back(0);
    }
    _size[0][i] = p;
  }

  for (int i = 0; i < B; i++) {
    cin >> p;
    if (p == N) ret++;
    if (i != B - 1) {
      adj[1][i].push_back(i + 1);
    } else {
      adj[1][i].push_back(0);
    }
    _size[1][i] = p;
  }

  // 1:1
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      if (_size[0][i] + _size[1][j] == N) ret++;
    }
  }

  // N:1
  int idx = 0;
  while (true) {
    if (idx > 1) break;
    int a_size = idx % 2 == 0 ? A : B;
    int b_size = idx % 2 == 0 ? B : A;

    for (int i = 0; i < a_size; i++) {

      int start = 0;
      while (start < b_size) {
        int sum = _size[idx % 2][i];
        int cnt = 0, idx2 = start, sum2 = 0;
        
        while (true) {
          sum += _size[(idx + 1) % 2][idx2];
          if (i == 0) sum2 += _size[(idx + 1) % 2][idx2];
          idx2 = adj[(idx + 1) % 2][idx2][0];
          cnt++;
          if (sum == N && cnt >= 2) {
            ret++;
          }
          if (sum2 == N && cnt >= 2) {
            ret++;
          };
          if (cnt == b_size) break;
        }

        start++;
      }
    }

    idx++;
  }

  cout << ret << '\n';

  return 0;
}