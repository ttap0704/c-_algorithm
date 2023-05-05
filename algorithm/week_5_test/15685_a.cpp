#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, a[101][101], y, x, d, g, ret;
vector<int> dragon[4][21];

void makeDragon () {
  for (int i = 0; i < 4; i++) {
    dragon[i][0].push_back(i);
    dragon[i][1].push_back((i + 1) % 4);

    for (int j = 2; j <= 20; j++) {
      int n = dragon[i][j - 1].size();

      for (int k = n - 1; k >= 0; k--) {
        dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
      }
      
      for (int k = 0; k < n; k++) {
        dragon[i][j].push_back(dragon[i][j - 1][k]);
      }
    }
  }
}

void go (int x, int y, int d, int g) {
  a[x][y] = 1;

  for (int i = 0; i <= g; i++) {
    for (int j = 0; j < dragon[d][i].size(); j++) {
      x += dx[dragon[d][i][j]];
      y += dy[dragon[d][i][j]];

      a[x][y] = 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  makeDragon();

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> x >> y >> d >> g;
    go(x, y, d, g);
  }

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) ret++;
    }
  }

  cout << ret << '\n';
  
  return 0;
}