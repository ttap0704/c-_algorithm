#include <bits/stdc++.h>
using namespace std;

int N, M, mn = 64;
char a[54][54];
vector<pair<int, int>> v;
string WB[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};
string BW[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N - 7; i++) {
    for (int j = 0; j < M - 7; j++) {
      v.push_back({i, j});
    }
  }

  for (pair<int, int> p : v) {
    int cnt1 = 0;
    int cnt2 = 0;

    int y = 0;
    for (int i = p.first; i < p.first + 8; i++) {
      int x = 0;
      for (int j = p.second; j < p.second + 8; j++) {
        if (a[i][j] != WB[y][x]) {
          cnt1++;
        }
        if (a[i][j] != BW[y][x]) cnt2++;
        x++;
      }
      y++;
    }

    mn = min(mn, cnt1);
    mn = min(mn, cnt2);
  }

  cout << mn << '\n';

  return 0;
}