#include <bits/stdc++.h>
using namespace std;

int N, num, ret, a[104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = N - 1; i >= 0; i--) {
    while (a[i] <= a[i - 1]) {
      a[i - 1] -= 1;
      ret++;
    }
  }

  cout << ret << '\n';
  
  return 0;
}