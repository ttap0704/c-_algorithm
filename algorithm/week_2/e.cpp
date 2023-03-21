#include <bits/stdc++.h>
using namespace std;

const int V = 3;
bool visited[V][V];
const int mp[V][V] = {
  {1, 0, 1},
  {1, 0, 1},
  {0, 1, 1}
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go (int y, int x) {
  visited[y][x] = 1;
  cout << y << " : " << x << "\n";
  
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny < 0 || ny >= V || nx < 0 || nx >= V ) continue;
    if(mp[ny][nx] == 0) continue;    
    if (visited[ny][nx]) continue;
    go(ny, nx);
  }
}

int main () {

  go(0, 0);
  return 0;
}