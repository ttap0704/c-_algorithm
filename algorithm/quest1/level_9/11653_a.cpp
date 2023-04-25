#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (N != 1) {

    int i = 2;
    while (true) {
      if (N % i == 0) {
        N /= i;
        cout << i << '\n';
        break;
      }

      i++;
      if (i > N) break;
    }
    if (i > N) break;
  }

  return 0;
}