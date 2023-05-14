#include <bits/stdc++.h>
using namespace std;

struct Shark {
  int y, x, ti;
};
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, a[22][22], visited[22][22], cnt = 2, ret = 0, level = 2, by, bx;
vector<Shark> v;

bool customSort (Shark a, Shark b) {
  if (a.ti == b.ti) {
    if (a.y == b.y) {
      return a.x < b.x;
    } else {
      return a.y < b.y;
    }
  } else {
    return a.ti < b.ti;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<Shark> q;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];

      if (a[i][j] == 9) q.push({i, j, 0}), visited[i][j] = 1;
    }
  }


  while (true) {
    if (v.size()) {
      // cout << '\n';
      sort(v.begin(), v.end(), customSort);
      // for (Shark s : v) cout << s.y << " : " << s.x << " : " << s.ti << '\n';

      memset(visited, 0, sizeof(visited));
      a[by][bx] = 0;
      a[v[0].y][v[0].x] = 9;
      visited[v[0].y][v[0].x] = 1;
      q.push(v[0]);
      ret += v[0].ti;
      cnt--;
      v.clear();

      // cout << "ret : " << ret << '\n';
      // cout << "level : " << level << '\n';
      if (cnt == 0) {
        level++;
        cnt = level;
      }
    }
    by = q.front().y;
    bx = q.front().x;

    while (q.size()) {
      int y = q.front().y;
      int x = q.front().x;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] > level || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx, visited[y][x]});
        if (a[ny][nx] < level && a[ny][nx] > 0) v.push_back({ny, nx, visited[y][x]});

      }      
    }

    if (v.size() == 0) {
      break;
    }
  }

  cout << ret << '\n';
    
  return 0;
}