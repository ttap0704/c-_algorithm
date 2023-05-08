#include <bits/stdc++.h>
using namespace std;

int N, a, ret = -1001, sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a;
    sum += a;
    ret = max(ret, sum);
    if (sum < 0) sum = 0;
  }

  cout << ret << '\n';

  return 0;
}