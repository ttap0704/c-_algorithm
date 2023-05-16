#include <bits/stdc++.h>
using namespace std;

int N, a[54], visited[54], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  if (N == 1) {
    cout << a[0] << '\n';
    return 0;
  }

  sort(a, a + N);

  for (int i = 0; i < N; i += 2) {
    if (a[i] <= 0 && a[i + 1] <= 0 && a[i] + a[i + 1] < a[i] * a[i + 1]) {
      ret += (a[i] * a[i + 1]);
      visited[i] = 1;
      visited[i + 1] = 1;
    }
  }

  for (int i = N - 1; i >= 0; i -= 2) {
    if (a[i] > 0 && a[i - 1] > 0 && a[i] + a[i - 1] < a[i] * a[i - 1]) {
      ret += (a[i] * a[i - 1]);
      visited[i] = 1;
      visited[i - 1] = 1;
    }
  }

  for (int i = 0; i < N; i++) if (!visited[i]) ret += a[i];

  cout << ret << '\n';

  return 0;
}