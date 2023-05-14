#include <bits/stdc++.h>
using namespace std;

int T, num, d, a[4][8], mid1 = 2, mid2 = 6, ret;
char c;

void _rotate (int num, int d) {
  vector<int> tmp;
  for (int i = 0; i < 8; i++) tmp.push_back(a[num][i]);
  if (d == 1) rotate(tmp.begin(), tmp.begin() + tmp.size() - 1, tmp.end());
  else if (d == -1) rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
  for (int i = 0; i < 8; i++) a[num][i] = tmp[i];
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c;
      a[i][j] = (c - '0'); 
    }
  }

  cin >> T;
  while (T--) {
    cin >> num >> d;
    --num;

    vector<pair<int, int>> v;
    v.push_back({num, d});
    int gap = 1;
    bool by_flag = 1, ny_flag = 1;
    while (true) {
      int by = num - gap;
      int ny = num + gap;
      if (by < 0 && ny >= 4) break;

      d *= -1;

      if (by_flag && by >= 0 && a[by + 1][mid2] != a[by][mid1]) v.push_back({by, d});
      else by_flag = 0;

      if (ny_flag && ny < 4 && a[ny - 1][mid1] != a[ny][mid2]) v.push_back({ny, d});
      else ny_flag = 0;

      gap++;
    }

    for (pair<int, int> p : v) _rotate(p.first, p.second);
  }

  for (int i = 0; i < 4; i++) {
    if (a[i][0] == 1) ret += pow(2, i);
  }

  cout << ret << '\n';
  
  return 0;
}