#include <bits/stdc++.h>
using namespace std;

int N, sum = 1, num = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while (true) {
    sum += num;
    if (N < sum) break;
    else num++;
  }

  int x = num - (N - (sum  - num));
  int y = 1 + (N - (sum  - num));

  if (num % 2 == 1) {
    cout << x << '/' << y << '\n';
  } else {
    cout << y << '/' << x << '\n';
  }

  return 0;
}