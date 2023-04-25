#include <bits/stdc++.h>
using namespace std;

int N, K, i = 0, i2= 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  while (i != K) {
    if (N % i2 == 0) {
      i++;
    }
    if (i == K || i2 > N) break;
    i2++;
  }

  if (i2 > N && i < N) {
    cout << 0 << '\n';
  } else {
    cout << i2 << '\n';
  }

  return 0;
}