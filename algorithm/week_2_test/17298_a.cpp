#include <bits/stdc++.h>
using namespace std;

int N, num, a[1000004], b[1000004], mx;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (a[i] < a[j]) {
        b[i] = a[j];
        break;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << b[i] << " ";
  }

  return 0;
}