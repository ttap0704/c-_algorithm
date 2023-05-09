#include <bits/stdc++.h>
using namespace std;

int N, num, lis[1001], len = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    auto pos = lower_bound(lis, lis + len, num);
    if (*pos == 0) len++;
    *pos = num;
  }

  cout << len << '\n';

  return 0;
}