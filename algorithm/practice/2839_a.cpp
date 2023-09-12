#include <bits/stdc++.h>
using namespace std;

int N, five, three, n;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  n = N;

  five = N / 5;
  N %= 5;

  while (five >= 0) {
    if (N % 3 != 0) {
      five--;
      N += 5;
    } else {
      three = N / 3;
      break;
    }
  }

  if ((three * 3) + (five * 5) == n) {
    cout << three + five << '\n';
  }  else {
    cout << -1 <<'\n';
  }

  return 0;
}