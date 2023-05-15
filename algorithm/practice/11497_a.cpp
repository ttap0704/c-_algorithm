#include <bits/stdc++.h>
using namespace std;

int T, N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;
    
    int a[N];
    int b[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);

    int mid = N / 2, cnt = 0, idx = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (cnt % 2 == 0) {
        b[mid + idx] = a[i];
        idx += 1;
      } else {
        b[mid - idx] = a[i];
      }
      cnt++;
    }

    int mx = -1e9;
    for (int i = 0; i < N; i++) {
      if (i != N - 1) {
        if (mx < (abs(b[i] - b[i + 1]))) {
          mx = abs(b[i] - b[i + 1]);
        }
      } else {
        if (mx < (abs(b[i] - b[0]))) {
          mx = abs(b[i] - b[0]);
        }
      }
    }

    cout << mx << '\n';
  }

  return 0;
}