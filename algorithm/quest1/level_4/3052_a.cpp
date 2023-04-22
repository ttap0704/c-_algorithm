#include <bits/stdc++.h>
using namespace std;

int N = 10, num, a[43];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < N; i++) {
    cin >> num;

    a[num % 42] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < 43; i++) {
    if (a[i]) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}