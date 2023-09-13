#include <bits/stdc++.h>
using namespace std;

int N, a[11], b[11];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= N; i++) {
    int j = 1;
    while (a[i]) {
      if (b[j] == 0) {
        a[i]--;
      }
      j++;
    }

    while (b[j]) j++;
    b[j] = i;
  }

  for (int i = 1; i <= N; i++) {
    cout << b[i] << ' ';
  }

  return 0;
}