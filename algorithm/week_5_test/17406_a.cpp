#include <bits/stdc++.h>
using namespace std;

struct Triple {
  int r, c, s;

  pair<int, int> getStart () {
    return {(r - s - 1), (c - s - 1)};
  }

  pair<int, int> getEnd () {
    return {(r + s - 1), (c + s - 1)};
  }
};

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int N, M, K, r, c, s, a[54][54], mn = 1e9;
vector<Triple> v;
vector<int> idx_v;

void rotateArray (Triple t, int b[54][54]) {
  pair<int, int> s = t.getStart();
  pair<int, int> e = t.getEnd();

  int tmp[54][54];
  memcpy(tmp, b, sizeof(tmp));
  while (s.first < e.first) {
    int y = s.first;
    int x = s.second;
    int idx = 0;
    while (true) {
      int ny, nx;
      if (y == s.first && x == e.second) idx++, ny = s.first + 1, nx = e.second;
      else if (y == e.first && x == e.second) idx++, ny = e.first, nx = e.second - 1;
      else if (y == e.first && x == s.second) idx++, ny = e.first - 1, nx = s.second;
      else {
        ny = y + dy[idx];
        nx = x + dx[idx];
      }

      tmp[ny][nx] = b[y][x];
      if (ny == s.first && nx == s.second) break;
      
      y = ny;
      x = nx;
    }

    s.first++;
    s.second++;
    e.first--;
    e.second--;
  }

  memcpy(b, tmp, sizeof(tmp));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    cin >> r >> c >> s;
    v.push_back({r, c, s});
    idx_v.push_back(i);
  }

  do {
    int b[54][54];
    memcpy(b, a, sizeof(b));

    for (int i : idx_v) {
      rotateArray(v[i], b);
    }

    for (int i = 0; i < N; i++) {
      int sum = 0;
      for (int j = 0; j < M; j++) {
        sum += b[i][j];
      }

      mn = min(mn, sum);
    }

  } while (next_permutation(idx_v.begin(), idx_v.end()));

  cout << mn << '\n';

  return 0;
}