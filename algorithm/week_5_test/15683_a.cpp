#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[8][8], ret = 1e9;
map<int, vector<vector<int>>> mp;
vector<pair<int, int>> v;

void go (int start, int b[8][8]) {
  if (start == v.size()) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (b[i][j] == 0) cnt++;
      }
    }

    ret = min(ret, cnt);
    return;
  }

  int y = v[start].first;
  int x = v[start].second;
  int cur_c = a[y][x];
  for (int i = 0; i < mp[cur_c].size(); i++) {
    int c[8][8];
    memcpy(c, b, sizeof(c));

    int idx = 0;
    while (idx < mp[cur_c][i].size()) {
      int ny = y;
      int nx = x;
      while (true) {
        ny += dy[mp[cur_c][i][idx]];
        nx += dx[mp[cur_c][i][idx]];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || c[ny][nx] == 6) break; 
        if (c[ny][nx] == 0) c[ny][nx] = 7;
      }
      idx++;
    }
    
    go(start + 1, c);
  }  
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  mp[1].push_back({0}); mp[1].push_back({1}); mp[1].push_back({2}); mp[1].push_back({3});
  mp[2].push_back({0, 2}); mp[2].push_back({1, 3});
  mp[3].push_back({0, 1}); mp[3].push_back({1, 2}); mp[3].push_back({2, 3}); mp[3].push_back({3, 0});
  mp[4].push_back({3, 0, 1}); mp[4].push_back({0, 1, 2}); mp[4].push_back({1, 2, 3}); mp[4].push_back({2, 3, 0});
  mp[5].push_back({0, 1, 2, 3});

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      
      if (a[i][j] && a[i][j] != 6) v.push_back({i, j});
    }
  }

  go(0, a);

  cout << ret << '\n';

  return 0;
}