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

    auto *pos = lower_bound(lis, lis + len, n);
    if (*pos == 0) len++;
    *pos = n;
  }

  cout << len << '\n';

  return 0;
}