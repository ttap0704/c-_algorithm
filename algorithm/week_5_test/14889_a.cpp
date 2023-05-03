#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[24][24], mn = INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i < (1 << N); i++) {
    vector<int> v, v2;
    if (__builtin_popcount(i) != N / 2) continue;
    for (int j = 0; j < N; j++) { 
      if (i & (1 << j)) {
        v.push_back(j);
      } else v2.push_back(j);
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int j = 0; j < N / 2; j++) {
      for (int k = 0; k < N / 2; k++) {
        if (j != k) {
          sum1 += a[v[j]][v[k]];
          sum2 += a[v2[j]][v2[k]];
        }
      }
    }

    mn = min(mn, abs(sum1 - sum2));
  }

  cout << mn << '\n';

  return 0;
}