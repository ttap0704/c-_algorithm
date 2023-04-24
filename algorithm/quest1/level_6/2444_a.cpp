#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < (N * 2) - 1; i++) {
    int nx1 = abs(N - 1 - i);
    int nx2 = (N - 1 + i);
    if (i >= N) {
      nx2 -= nx1 + abs(N - i - 1);
    }
    for (int j = 0; j < (N * 2) - 1; j++) {
      if (nx2 >= j && j >= nx1) cout << '*';
      else {
        if (nx2 > j) cout << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}