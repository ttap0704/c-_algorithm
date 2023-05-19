#include <bits/stdc++.h>
#define MAX_N 14
#define MAX_K 1000
using namespace std;

struct Tree {
  int y, x, age;
};

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, x, y, z, a[MAX_N][MAX_N], b[MAX_N][MAX_N];
vector<int> v[MAX_N][MAX_N];

bool customSort (Tree a, Tree b) {
  return a.age < b.age;
}

void springSummer () {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (v[i][j].size()) {
        sort(v[i][j].begin(), v[i][j].end());

        vector<int> tmp;
        int dead_num = 0;
        for (int t : v[i][j]) {
          if (a[i][j] >= t) {
            a[i][j] -= t;
            tmp.push_back(t + 1);
          } else {
            dead_num += t / 2;
          }
        }

        v[i][j] = tmp;
        a[i][j] += dead_num;
      }
    }
  }
}

void fall () {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (v[i][j].size()) {
        
        for (int t : v[i][j]) {
          if (t % 5 == 0) {
            for (int d = 0; d < 8; d++) {
              int ny = i + dy[d];
              int nx = j + dx[d];

              if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
              v[ny][nx].push_back(1);
            }
          }
        }
      }
    }
  }
}

void winter () {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      a[i][j] += b[i][j];
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&a[0][0], &a[0][0] + MAX_N * MAX_N, 5);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> x >> y >> z;
    v[x][y].push_back(z);
  }

  for (int i = 0; i < K; i++) {
    springSummer();
    fall();
    winter();
  }

  int ret = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      ret += v[i][j].size(); 
    }
  }

  cout << ret << '\n';

  return 0;
}