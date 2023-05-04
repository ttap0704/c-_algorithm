#include <bits/stdc++.h>
using namespace std;

int N, K, L, a[104][104], ay, ax, se, cnt;
char di;
queue<char> q;
deque<pair<int, int>> dq;

void rotate90 (char d) {
  int tmp[104][104];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (d == 'L') {
        tmp[i][j] = a[N - j - 1][i];
      } else if (d == 'D') {
        tmp[i][j] = a[j][N - i - 1];
      }
    }
  }

  for (int i = 0; i < dq.size(); i++) {
    if (d == 'L') {
      int tmp_second = dq[i].second;
      dq[i].second = N - 1 - dq[i].first;
      dq[i].first = tmp_second;
    } else if (d == 'D') {
      int tmp_first = dq[i].first;
      dq[i].first = N - 1 - dq[i].second;
      dq[i].second = tmp_first;
    }
    
  }

  memcpy(a, tmp, sizeof(a));
}

void move () {
  if (a[dq.back().first][dq.back().second + 1] == 0) {
    a[dq.front().first][dq.front().second] = 0;
    dq.pop_front();
  }

  dq.push_back({dq.back().first, dq.back().second + 1});
  a[dq.back().first][dq.back().second] = 2;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  a[0][0] = 2;
  dq.push_back({0, 0});
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> ay >> ax;
    a[ay - 1][ax - 1] = 1;
  }

  cin >> L;
  for (int i = 0; i < L; i++) {
    cin >> se >> di;
    for (int j = q.size(); j < se; j++) {
      if (j == se - 1) q.push(di);
      else q.push('G');
    }
  }

  while (true) {
    cnt++;
    if (dq.back().second + 1 >= N) break;
    if (a[dq.back().first][dq.back().second + 1] == 2) break;

    move();
    if (q.size()) {
      if (q.front() != 'G') {
        rotate90(q.front());
      }
      q.pop();
    }
  }

  cout << cnt << '\n';

  return 0;
}