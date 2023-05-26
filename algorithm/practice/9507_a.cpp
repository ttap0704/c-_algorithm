#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N, fibo[70];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  fibo[0] = 1; fibo[1] = 1; fibo[2] = 2; fibo[3] = 4;
  for (int i = 4; i <= 67; i++) fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];

  while (T--) {
    cin >> N;

    cout << fibo[N] << '\n';
  }

  return 0;
}