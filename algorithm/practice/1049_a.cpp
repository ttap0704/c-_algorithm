#include <bits/stdc++.h>
using namespace std;

int N, M, mn1 = 1004, mn2 = 1004, a, b, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    mn1 = min(mn1, a);
    mn2 = min(mn2, b);
  }

  int sum1 = (N / 6 + 1) * mn1;
  int sum2 = (N / 6 * mn1) + (N % 6 * mn2);
  int sum3 = N * mn2;
  cout << min(sum1, min(sum2, sum3)) << '\n';

  return 0;
}