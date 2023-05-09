#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, T, n, x, d, k, visited[54][54], ret = 0;
deque<int> dq[54];

void rotateDQ (int x, int d, int k) {
  while (x <= N) {
    int cnt = k;
    while (cnt) {
      if (d == 0) {
        dq[x].push_front(dq[x].back());
        dq[x].pop_back();
      } else {
        dq[x].push_back(dq[x].front());
        dq[x].pop_front();
      }

      cnt--;
    }

    x += x;
  }
}

bool removeNumber(int y, int x) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> v;
  visited[y][x] = 1;
  q.push({y, x});
  int num = dq[y][x];

  while (q.size()) {
    tie(y, x) = q.front();
    v.push_back({y, x});
    q.pop();
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (nx < 0) nx = M - 1;
      else if (nx >= M) nx = 0;

      if (ny < 1 || ny > N || visited[ny][nx] || !dq[ny][nx]) continue;
      if (dq[ny][nx] == num) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }

  if (v.size() > 1) {
    for (pair<int, int> p : v) dq[p.first][p.second] = 0;
    return true;
  } else {
    return false;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> T;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> n;
      dq[i].push_back(n);
    }
  }

  for (int c = 0; c < T; c++) {
    cin >> x >> d >> k;

    memset(visited, 0, sizeof(visited));
    rotateDQ(x, d, k);
    bool flag = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < M; j++) {
        if (visited[i][j] || !dq[i][j]) continue;
        bool check = removeNumber(i, j);
        if (check) {
          flag = 1;
        }
      }
    }
    
    if (!flag) {
      int sum = 0, cnt = 0;
      for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
          if (dq[i][j]) cnt++, sum += dq[i][j];
        }
      } 

      double avg = (double) sum / (double) cnt;
      for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
          if (dq[i][j] == 0) continue; 

          if ((double)dq[i][j] > avg) dq[i][j] -= 1;
          else if ((double)dq[i][j] < avg) dq[i][j] += 1;
        }
      } 
    }
  }
  
  
  for (int i = 1; i <= N; i++) {
    for (int j : dq[i]) ret += j;
  }

  cout << ret << '\n';

  return 0;
}