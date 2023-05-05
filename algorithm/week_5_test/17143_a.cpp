#include <bits/stdc++.h>
using namespace std;

struct Info {
  int s, d, z;
};

struct AddInfo {
  int pos, y, x, z;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, M, S, r, c, s, d, z, pos = -1, a[104][104];
long long ret;
Info info[10004];
deque<AddInfo> dq;

void moveShark () {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == -1) continue;

      int cur_id = a[i][j];
      int ny = i;
      int nx = j;
      for (int k = 0; k < info[cur_id].s; k++) {
        ny += dy[info[cur_id].d];
        nx += dx[info[cur_id].d];

        if (info[cur_id].d <= 1 && ny == 0) info[cur_id].d = 1;
        else if (info[cur_id].d <= 1 && ny == N - 1) info[cur_id].d = 0;
        else if (info[cur_id].d >= 2 && nx == 0) info[cur_id].d = 2;
        else if (info[cur_id].d >= 2 && nx == M - 1) info[cur_id].d = 3;
      }
      dq.push_back({cur_id, ny, nx, info[cur_id].z});
      a[i][j] = -1;
    }
  }
}

void catchShark () {
  for (int i = 0; i < N; i++) {
    if (a[i][pos] != -1) {
      ret += info[a[i][pos]].z;
      a[i][pos] = -1;
      break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(a, -1, sizeof(a));

  cin >> N >> M >> S;
  for (int i = 0; i < S; i++) {
    cin >> r >> c >> s >> d >> z;

    a[--r][--c] = i;
    info[i] = {s, --d, z};
  }

  while (pos < M - 1) {
    pos++;

    catchShark();
    moveShark();
    while (dq.size()) {
      AddInfo _info = dq.front();
      dq.pop_front();

      if (a[_info.y][_info.x] < _info.z) {
        a[_info.y][_info.x] = _info.pos;
      }
    }
  }

  cout << ret << '\n';

  return 0;
}