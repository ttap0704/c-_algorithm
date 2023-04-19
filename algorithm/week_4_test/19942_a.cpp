#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[4], b[16][5], mn = INF, c[5];
vector<int> v;
map<int, vector<vector<int>>> ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < (1 << N); i++) {
    memset(c, 0, sizeof(c));
    vector<int> tmp;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < 5; k++) {
          c[k] += b[j][k];
        }
        tmp.push_back(j + 1);
      }
    }

    if (a[0] <= c[0] && a[1] <= c[1] && a[2] <= c[2] && a[3] <= c[3] && mn >= c[4]) {
      mn = min(mn, c[4]);
      ret[mn].push_back(tmp);
    }
  }


  if (mn == INF) {
    cout << -1 << '\n';
  } else {
    sort(ret[mn].begin(), ret[mn].end());
    cout << mn << '\n';
    for (int i : ret[mn][0]) {
      cout << i << ' ';
    }
  }
  
  return 0;
}