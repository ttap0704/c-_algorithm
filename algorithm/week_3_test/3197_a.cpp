#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, visiteds[1504][1504], visitedw[1504][1504], y, x, turn;
char a[1504][1504];
queue<pair<int, int>> wq, wq2, sq, sq2;

void emptySq() {
  queue<pair<int, int>> tmpq;
  sq2 = tmpq;
}

void emptyWq() {
  queue<pair<int, int>> tmpq;
  wq2 = tmpq;
}

bool moveS () {
  while (sq.size()) {
    tie(y, x) = sq.front();
    sq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visiteds[ny][nx]) continue;
      visiteds[ny][nx] = 1;
      if (a[ny][nx] == 'X') sq2.push({ny, nx});
      else if (a[ny][nx] == '.') sq.push({ny, nx});
      else if (a[ny][nx] == 'L') {
        return true;
      }
    }
  }

  return false;
}

void removeIce() {
  while (wq.size()) {
    tie(y, x) = wq.front();
    wq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visitedw[ny][nx]) continue;
      visitedw[ny][nx] = 1;
      if (a[ny][nx] == 'X') {
        a[ny][nx] = '.';
        wq2.push({ny, nx});
      } else if (a[ny][nx] == '.') {
        wq.push({ny, nx});
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'L' && sq.size() == 0) {
        sq.push({i, j});
        visiteds[i][j] = 1;
      };
      if (a[i][j] == '.' || a[i][j] == 'L') {
        wq.push({i, j});
        visitedw[i][j] = 1;
      };
    }
  }

  while (true) {
    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < M; j++) {
    //     cout << a[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
    if (moveS()) break;
    removeIce();
    sq = sq2;
    wq = wq2;
    emptySq();
    emptyWq();
    turn++;
  }

  cout << turn << "\n";

  // cout << "\n";
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  
  return 0;
}