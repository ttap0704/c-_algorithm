#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[21][21], mn = INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i < (N * N); i++) {
    int cnt = 0;
    vector<int> v, v2;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        cnt++;
        v.push_back(j + 1);
      } else v2.push_back(j + 1);
    }
    if (cnt != N / 2) continue;

    int sum1 = 0;
    int sum2 = 0;
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        if (j != k) {
          sum1 += a[v[j]][v[k]];
          sum2 += a[v2[j]][v2[k]];
        }
      }
    }

    mn = min(mn, abs(sum1 - sum2));
    if (mn == abs(sum1 - sum2)) {
      cout << "mn : " << mn << '\n';
      cout << "v : ";
      for (int j : v) {
        cout << j << ' ';
      }
      cout << '\n';
      cout << "v2 : ";
      for (int j : v2) {
        cout << j << ' ';
      }
      cout << '\n';
    }
  }

  cout << mn << '\n';

  return 0;
}