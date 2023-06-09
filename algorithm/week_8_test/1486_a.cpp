#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, T, D, a[26][26], b[3000][3000], ret;
vector<int> v;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> T >> D;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      if (tolower(c) != c) a[i][j] = (c - 'A');
      else a[i][j] = (c - 'a') + 26;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      v.push_back(i * 100 + j);
    }
  }

  fill(&b[0][0], &b[0][0] + (3000 * 3000), INF);
  ret = a[0][0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 4; d++) {
        int ny = i + dy[d];
        int nx = j + dx[d];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        int gap = abs(a[ny][nx] - a[i][j]);
        if (gap > T) continue;
        if (a[ny][nx] > a[i][j]) {
          b[i * 100 + j][ny * 100 + nx] = gap * gap;
        } else {
          b[i * 100 + j][ny * 100 + nx] = 1;
        }
      }
    }
  }

  for (int k : v) {
    for (int i : v) {
      for (int j : v) {
        b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
      }
    }
  }

  for(int j : v){ 
    if(D >= b[0][j] + b[j][0]){  
      ret = max(ret, a[j / 100][j % 100]);
    }
  } 

  cout << ret << '\n';

  return 0;
}