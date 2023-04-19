#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, visited_w[1504][1504], visited_s[1504][1504], turn = 0;
char a[1504][1504];
queue<pair<int, int>> wq, sq, wq2, sq2;

void clearWq2 () {
  queue<pair<int, int>>  tmp;
  wq2 = tmp;
}

void clearSq2 () {
  queue<pair<int, int>>  tmp;
  sq2 = tmp;
}

void removeIce () {
  int y, x;
  while (wq.size()) {
    tie(y, x) = wq.front();
    wq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited_w[ny][nx]) continue;
      if (a[ny][nx] == 'X') {
        a[ny][nx] = '.';
        wq2.push({ny, nx});
        visited_w[ny][nx] = 1;
      } else if (a[ny][nx] == '.') {
        wq.push({ny, nx});
        visited_w[ny][nx] = 1;
      }
    }
  }

  wq = wq2;
}

bool moveSwan () {
  int y, x;
  while (sq.size()) {
    tie(y, x) = sq.front();
    sq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited_s[ny][nx]) continue;
      if (a[ny][nx] == 'X') {
        sq2.push({ny, nx});
        visited_s[ny][nx] = 1;
      } else if (a[ny][nx] == '.') {
        sq.push({ny, nx});
        visited_s[ny][nx] = 1;
      } else if (a[ny][nx] == 'L') {
        return true;
      }
    }
  }

  sq = sq2;
  return false;
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      
      if (a[i][j] == '.' || a[i][j] == 'L') {
        wq.push({i, j});
        visited_w[i][j] = 1;
      }
      if (a[i][j] == 'L' && sq.size() == 0) {
        sq.push({i, j});
        visited_s[i][j] = 1;
      }
    }
  }

  while (true) {
    if (moveSwan()) break;
    turn++;
    removeIce();
    clearSq2();
    clearWq2();
  }

  cout << turn << "\n";

  return 0;
}