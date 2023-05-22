#include <bits/stdc++.h>
using namespace std;

struct Mal {
  int y, x, d;
} mal[12];
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int N, K, a[14][14], y, x, d, ret;
vector<int> v[14][14];

bool whiteBlue (int y, int x, int ny, int nx, int target_mal) {
  deque<int> dq;
  int _size = v[y][x].size();
  for (int i = _size - 1; i >= 0; i--) {
    int mal_num = v[y][x][i];
    dq.push_back(mal_num);
    v[y][x].pop_back();
    if (mal_num == target_mal) break;
  }

  while (dq.size()) {
    int mal_num = dq.back();
    mal[mal_num].y = ny;
    mal[mal_num].x = nx;
    v[ny][nx].push_back(mal_num);
    dq.pop_back();
  }

  return v[ny][nx].size() >= 4;
}

bool red (int y, int x, int ny, int nx, int target_mal) {
  deque<int> dq;
  int _size = v[y][x].size();
  for (int i = _size - 1; i >= 0; i--) {
    int mal_num = v[y][x][i];
    dq.push_back(mal_num);
    v[y][x].pop_back();
    if (mal_num == target_mal) break;
  }

  while (dq.size()) {
    int mal_num = dq.front();
    mal[mal_num].y = ny;
    mal[mal_num].x = nx;
    v[ny][nx].push_back(mal_num);
    dq.pop_front();
  }
  return v[ny][nx].size() >= 4;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= K; i++) {
    cin >> y >> x >> d;
    v[y][x].push_back(i);
    mal[i] = {y, x, d - 1};
  }

  while (true) {
    if (ret >= 1000) break;

    int flag = 0;
    for (int i = 1; i <= K; i++) {
      y = mal[i].y; x = mal[i].x; d = mal[i].d;

      int ny = y + dy[d];
      int nx = x + dx[d];

      if (ny < 1 || ny > N || nx < 1 || nx > N || a[ny][nx] == 2) {
        if (mal[i].d == 0) mal[i].d = 1;
        else if (mal[i].d == 1) mal[i].d = 0;
        else if (mal[i].d == 2) mal[i].d = 3;
        else if (mal[i].d == 3) mal[i].d = 2;
        
        int ny2 = y + dy[mal[i].d];
        int nx2 = x + dx[mal[i].d];

        if (ny2 < 1 || ny2 > N || nx2 < 1 || nx2 > N || a[ny2][nx2] == 2) {
          continue;
        } else {
          if (a[ny2][nx2] == 0) {
            if (whiteBlue(y, x, ny2, nx2, i)) {
              flag = 1;
              break;
            }
          } else {
            if (red(y, x, ny2, nx2, i)) {
              flag = 1;
              break;
            }
          }
        }
      } else if (a[ny][nx] == 0) {
        if (whiteBlue(y, x, ny, nx, i)) {
          flag = 1;
          break;
        }
      } else {
        if (red(y, x, ny, nx, i)) {
          flag = 1;
          break;
        }
      }
    }


    // cout << '\n';
    // for (int i = 1; i <= K; i++) {
    //   cout << mal[i].y << " : " << mal[i].x << " : " << mal[i].d << '\n';
    // }
    ret++;
    if (flag) break;
  }

  if (ret >= 1000) cout << -1 << '\n';
  else cout << ret << '\n';

  return 0;
}