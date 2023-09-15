#include <bits/stdc++.h>
using namespace std;
struct Square {
  int y, x, k;
};

int N, a[130][130], white, blue;
queue<Square> q;

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
    Square s = q.front();
    int y = s.y, x = s.x, k = s.k;
    q.pop();

    int cur = a[y][x];
    bool flag = 1;
      
    for (int i = y; i < y + k; i++) {
      for (int j = x; j < x + k; j++) {
        if (a[i][j] != cur) {
          flag = 0;
          break;
        }
      }
      if (!flag) break;
    }

    if (flag) {
      if (cur == 1) blue++;
      else white++;
    } else {
      int next_n = k / 2;
      q.push({y, x, next_n});
      q.push({y, x + next_n, next_n});
      q.push({y + next_n, x + next_n, next_n});
      q.push({y + next_n, x, next_n});
    }
  }

  cout << white << '\n';
  cout << blue << '\n';

  return 0;
}