#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, a[100004], ret = INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];

    ret = max(ret, sum);
    if (sum < 0) sum = 0;
  }

  cout << ret << '\n';

  return 0;
}