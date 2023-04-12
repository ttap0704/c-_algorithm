#include <bits/stdc++.h>
using namespace std;

int N, a[3], visited[64][64][64], ret;
int at[6][3] = {
  {9, 3, 1},
  {9, 1, 3},
  {3, 9, 1},
  {3, 1, 9},
  {1, 3, 9},
  {1, 9, 3}
};

struct A {
  int a, b, c;
};
queue<A> q;
void solve(int a, int b, int c) {
  visited[a][b][c] = 1;
  q.push({a, b, c});

  while (q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();

    if (visited[0][0][0]) {
      ret = visited[0][0][0];
      break;
    }

    for (int i = 0; i < 6; i++) {
      int a_val = max(0, a - at[i][0]);
      int b_val = max(0, b - at[i][1]);
      int c_val = max(0, c - at[i][2]);

      if (visited[a_val][b_val][c_val]) continue;
      visited[a_val][b_val][c_val] = visited[a][b][c] + 1;
      q.push({a_val, b_val, c_val});
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  solve(a[0], a[1], a[2]);
  cout << ret - 1 << "\n";

  return 0;
}