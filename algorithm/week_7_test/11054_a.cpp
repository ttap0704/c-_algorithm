#include <bits/stdc++.h>
#define MAX_N 1004
using namespace std;

int N, n, lis[MAX_N], len;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;

    auto *lo_pos = lower_bound(lis, lis + len, n);
    if (*lo_pos == 0) len++;
    *lo_pos = n;

    for (int j = 0; j < N; j++) {
      cout << lis[j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}