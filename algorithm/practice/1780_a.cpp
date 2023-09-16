#include <bits/stdc++.h>
using namespace std;

struct Paper {
  int y, x, k;
};

int N, a[2200][2200];
queue<Paper> q;
map<int, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  q.push({0, 0, N});
  while (q.size()) {
    Paper tmp = q.front();
    int cur_y = tmp.y, cur_x = tmp.x, cur_k = tmp.k;
    q.pop();

    int color = a[cur_y][cur_x];
    bool flag = 1;

    for (int i = cur_y; i < cur_y + cur_k; i++) {
      for (int j = cur_x; j < cur_x + cur_k; j++) {
        if (color != a[i][j]) {
          flag = 0;
          break;
        }
      }
      if (!flag) break;
    }

    if (flag) {
      mp[color]++;
    } else {
      int next_k = cur_k / 3;
      for (int i = 0; i < 3; i++) {
        q.push({cur_y, cur_x + (next_k * i), next_k});
        q.push({cur_y + next_k, cur_x + (next_k * i), next_k});
        q.push({cur_y + (next_k * 2), cur_x + (next_k * i), next_k});
      }
    }
  }

  cout << mp[-1] << '\n';
  cout << mp[0] << '\n';
  cout << mp[1] << '\n';

  return 0;
}